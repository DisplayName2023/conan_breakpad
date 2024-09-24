#pragma once
#include <stdint.h>



namespace BreakpadCpp
{
    class Breakpad
    {
    public:
        static void Init();
        static int32_t number;
    };
    
}