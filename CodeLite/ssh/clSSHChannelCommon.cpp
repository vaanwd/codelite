#include "clSSHChannelCommon.hpp"

#include "StringUtils.h"
#include "cl_command_event.h"

#include <wx/regex.h>

#if USE_SFTP

#include "clModuleLogger.hpp"
INITIALISE_SSH_LOG(LOG, "Channel Reader Helper");

#include <libssh/libssh.h>

wxDEFINE_EVENT(wxEVT_SSH_CHANNEL_READ_ERROR, clCommandEvent);
wxDEFINE_EVENT(wxEVT_SSH_CHANNEL_WRITE_ERROR, clCommandEvent);
wxDEFINE_EVENT(wxEVT_SSH_CHANNEL_READ_OUTPUT, clCommandEvent);
wxDEFINE_EVENT(wxEVT_SSH_CHANNEL_READ_STDERR, clCommandEvent);
wxDEFINE_EVENT(wxEVT_SSH_CHANNEL_CLOSED, clCommandEvent);

namespace ssh
{
read_result channel_read_all(SSHChannel_t channel, std::string* out, bool is_stderr)
{
    while(true) {
        char buffer[4096 + 1];
        int bytes = ssh_channel_read_timeout(channel, buffer, sizeof(buffer) - 1, is_stderr ? 1 : 0, 5);
        if(bytes == SSH_ERROR) {
            // an error
            int exit_code = ssh_channel_get_exit_status(channel);
            LOG_DEBUG(LOG) << "channel read error. process exited with status code" << exit_code << endl;
            return read_result::SSH_IO_ERROR;

        } else if(bytes == SSH_EOF) {
            // channel closed
            int exit_code = ssh_channel_get_exit_status(channel);
            LOG_DEBUG(LOG) << "channel read eof. process exited with status code" << exit_code << endl;
            return read_result::SSH_SUCCESS;

        } else if(bytes == 0) {
            // timeout
            if(ssh_channel_is_eof(channel)) {
                int exit_code = ssh_channel_get_exit_status(channel);
                LOG_DEBUG(LOG) << "channel eof detected. process exited with status code" << exit_code << endl;
                return read_result::SSH_SUCCESS;

            } else {
                // timeout
                continue;
            }
        } else {
            LOG_DEBUG(LOG) << "read" << bytes << "bytes" << endl;
            buffer[bytes] = 0;
            out->append(buffer, bytes);
            continue;
        }
    }
}

read_result channel_read(SSHChannel_t channel, wxEvtHandler* handler, bool isStderr, bool wantStderr, long timeout_ms)
{
    // read in chunks of 16KiB
    char buffer[4096 + 1];
    int bytes = ssh_channel_read_timeout(channel, buffer, sizeof(buffer) - 1, isStderr ? 1 : 0, timeout_ms);
    if(bytes == SSH_ERROR) {
        // an error
        LOG_DEBUG(LOG) << "channel read error" << endl;
        int exit_code = ssh_channel_get_exit_status(channel);
        clCommandEvent event(wxEVT_SSH_CHANNEL_READ_ERROR);
        event.SetInt(exit_code);
        handler->QueueEvent(event.Clone());
        return read_result::SSH_IO_ERROR;

    } else if(bytes == SSH_EOF) {
        // channel closed
        LOG_DEBUG(LOG) << "channel read eof" << endl;
        int exit_code = ssh_channel_get_exit_status(channel);

        clCommandEvent event(wxEVT_SSH_CHANNEL_CLOSED);
        event.SetInt(exit_code);
        handler->QueueEvent(event.Clone());
        return read_result::SSH_CONN_CLOSED;

    } else if(bytes == 0) {
        // timeout
        if(ssh_channel_is_eof(channel)) {
            LOG_DEBUG(LOG) << "channel eof detected" << endl;
            int exit_code = ssh_channel_get_exit_status(channel);

            // send close event
            clCommandEvent event(wxEVT_SSH_CHANNEL_CLOSED);
            event.SetInt(exit_code);
            handler->QueueEvent(event.Clone());
            return read_result::SSH_CONN_CLOSED;

        } else {
            // timeout
            return read_result::SSH_TIMEOUT;
        }
    } else {
        LOG_DEBUG(LOG) << "read" << bytes << "bytes" << endl;
        buffer[bytes] = 0;
        clCommandEvent event((isStderr && wantStderr) ? wxEVT_SSH_CHANNEL_READ_STDERR : wxEVT_SSH_CHANNEL_READ_OUTPUT);
        event.SetStringRaw(buffer);
        handler->QueueEvent(event.Clone());
        return read_result::SSH_SUCCESS;
    }
}

wxString build_command(const std::vector<wxString>& command, const wxString& wd, const clEnvList_t& env)
{
    wxString cmd;
    if(!env.empty()) {
        // build each env in its own "export" statement
        for(const auto& e : env) {
            cmd << "export " << e.first << "=" << e.second << ";";
        }
    }

    if(!wd.empty()) {
        cmd << "cd " << StringUtils::WrapWithDoubleQuotes(wd) << " && ";
    }

    for(const wxString& c : command) {
        cmd << StringUtils::WrapWithDoubleQuotes(c) << " ";
    }

    if(cmd.EndsWith(" ")) {
        cmd.RemoveLast();
    }
    return cmd;
}
} // namespace ssh
#endif
