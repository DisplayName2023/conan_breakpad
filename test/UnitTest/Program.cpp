#include "gtest/gtest.h"

#include "Breakpad.h"

#include <iostream>


int add(int a, int b) {
    return a + b;
}

void causeCrash() {
    int* ptr = nullptr;
    *ptr = 1;  // This will cause a segmentation fault (access violation)
}

TEST(AddTest, PositiveNumbers) {

    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 20), 30);

    BreakpadCpp::Breakpad::init("C:/Temp/BreakpadDump");
    // causeCrash();
    std::cout << "Hello World!" << std::endl;
}

