#include "client/windows/handler/exception_handler.h"

#include <iostream>


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

void InitializeBreakpad() {
    google_breakpad::ExceptionHandler* handler =
        new google_breakpad::ExceptionHandler(
            L"C:\\Temp\\Breakpad",  // Path to save dump files
            nullptr,  // Filter callback
            DumpCallback,  // Minidump callback
            nullptr,  // Context pointer
            google_breakpad::ExceptionHandler::HANDLER_ALL);
}