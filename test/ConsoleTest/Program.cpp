
#include "Breakpad.h"

#include <iostream>



void causeCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    BreakpadCpp::Breakpad::init("C:/Temp/BreakpadDump");
    causeCrash();
    
    return 0;
}