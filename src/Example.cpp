#include "Example.h"

#include <iostream>

using namespace BreakpadCpp;

int32_t Breakpad::number = 10;

void Breakpad::Init()
{
    number = 20;
    std::cout << "Breakpad::Init() called" << std::endl;
}