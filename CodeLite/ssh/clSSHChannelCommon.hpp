#ifndef CLSSHCHANNELCOMMON_HPP
#define CLSSHCHANNELCOMMON_HPP

#if USE_SFTP

#include "clEnvironment.hpp"
#include "cl_command_event.h"
#include "codelite_exports.h"
#include "ssh/cl_ssh.h"

#include <vector>

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_SSH_CHANNEL_READ_ERROR, clCommandEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_SSH_CHANNEL_WRITE_ERROR, clCommandEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_SSH_CHANNEL_READ_OUTPUT, clCommandEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_SSH_CHANNEL_READ_STDERR, clCommandEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_SSH_CHANNEL_CLOSED, clCommandEvent);

namespace ssh
{
enum class read_result {
    SSH_TIMEOUT = -2,
    SSH_CONN_CLOSED = -1,
    SSH_IO_ERROR = 0,
    SSH_SUCCESS = 1,
};

/// return true if the read_result is not an error
inline bool result_ok(read_result res) { return res == read_result::SSH_SUCCESS || res == read_result::SSH_TIMEOUT; }

/// read from the channel
/// return ssh::read_result::* (see above)
WXDLLIMPEXP_CL read_result channel_read(SSHChannel_t channel, wxEvtHandler* handler, bool isStderr, bool wantStderr,
                                        long timeout_ms);

/// read all the output from the channel until it closes and reutrn it
WXDLLIMPEXP_CL read_result channel_read_all(SSHChannel_t channel, std::string* out, bool is_stderr);

/// build a oneliner command to execute on the remote host
WXDLLIMPEXP_CL wxString build_command(const std::vector<wxString>& command, const wxString& wd, const clEnvList_t& env);

} // namespace ssh
#endif

#endif // CLSSHCHANNEL_H
