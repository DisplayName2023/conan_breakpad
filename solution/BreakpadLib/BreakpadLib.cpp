#include "client/windows/handler/exception_handler.h"

#include <iostream>
#include <filesystem>

namespace BreakpadLib
{


// TODO: This is an example of a library function
static bool DumpCallback(const wchar_t* dump_path,
    const wchar_t* minidump_id,
    void* context,
    EXCEPTION_POINTERS* exinfo,
    MDRawAssertionInfo* assertion,
    bool succeeded) {
    wprintf(L"Dump path: %s\\%s.dmp\n", dump_path, minidump_id);
    return succeeded;
}

void InitializeBreakpad(const wchar_t* dumpDirName) {
    std::filesystem::create_directories(dumpDirName);

    google_breakpad::ExceptionHandler* handler =
        new google_breakpad::ExceptionHandler(
            dumpDirName,  // Path to save dump files
            nullptr,  // Filter callback
            DumpCallback,  // Minidump callback
            nullptr,  // Context pointer
            google_breakpad::ExceptionHandler::HANDLER_ALL);
}


}