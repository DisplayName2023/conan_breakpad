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

