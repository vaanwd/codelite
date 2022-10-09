#include "fmtClangFormat.hpp"

#include "Platform.hpp"

fmtClangFormat::fmtClangFormat()
{
    SetName("clang-format");
    SetFileTypes({ FileExtManager::TypeSourceCpp, FileExtManager::TypeSourceC, FileExtManager::TypeHeader,
                   FileExtManager::TypeJava, FileExtManager::TypeJS });
    SetDescription(_("A tool to format C/C++/Java/JavaScript/JSON/Objective-C/Protobuf/C# code"));
    SetHasConfigFile(true);
    SetConfigFilepath("$(WorkspacePath)/.clang-format");

    // local command
    wxString clang_format_exe;
    PLATFORM::Which("clang-format", &clang_format_exe);
    SetCommand({ clang_format_exe, "$(CurrentFileRelPath)" });
}

fmtClangFormat::~fmtClangFormat() {}