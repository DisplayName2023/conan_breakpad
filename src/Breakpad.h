#pragma once
#include <stdint.h>



namespace BreakpadCpp
{
    class Breakpad
    {
    public:
        static void init(const char* dumpDirName);
    };
    
}