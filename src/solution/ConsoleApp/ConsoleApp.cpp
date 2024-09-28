// ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../BreakpadDll/BreakpadFunctions.h"

// void InitializeBreakpad(const wchar_t* dumpDirName);

void CauseCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}

int main()
{
    std::cout << "Hello World!\n";

    //InitializeBreakpad();
    initBreakpad("C:/Temp/BreakpadDumps");
    CauseCrash();

    return 0;
}

