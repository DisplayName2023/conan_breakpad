#include "Breakpad.h"
#include "BreakpadFunctions.h"
#include <iostream>

using namespace BreakpadCpp;



void Breakpad::init(const char* dumpDirName)
{
    initBreakpad(dumpDirName);
    std::cout << "Breakpad::init() called" << std::endl;
}