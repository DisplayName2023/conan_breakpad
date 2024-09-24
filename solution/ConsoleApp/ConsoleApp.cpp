// ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "client/windows/handler/exception_handler.h"

#include <iostream>

void InitializeBreakpad();

void CauseCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}

int main()
{
    std::cout << "Hello World!\n";

    InitializeBreakpad();
    CauseCrash();

    return 0;
}

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
