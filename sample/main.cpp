#include <iostream>

#include "BreakpadCpp/Breakpad.h"



void causeCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}


int main()
{
    std::cout << "Hello World!\n";

    BreakpadCpp::Breakpad::init("C:/Temp/BreakpadDumps");
    causeCrash();

}
