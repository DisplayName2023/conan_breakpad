#include <iostream>

#include "BreakpadCpp/Breakpad.h"
#include "InvalidFunctions.h"


void causeCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}


int main()
{
    std::cout << "Hello World!\n";

    BreakpadCpp::Breakpad::init("C:/Temp/BreakpadDumps");
    // causeCrash();
    auto a = errorFunc5();
    std::cout << "After errorFunc5() " << a;

    errorFunc4();
    std::cout << "After errorFunc4() " << a;
}
