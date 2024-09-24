// ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../BreakpadDynamic/BreakpadFunctions.h"

// void InitializeBreakpad();

void CauseCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}

int main()
{
    std::cout << "Hello World!\n";

    //InitializeBreakpad();
    initBreakpad();
    CauseCrash();

    return 0;
}

