#include <iostream>

#include <gtest/gtest.h>


int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    int status = RUN_ALL_TESTS();

    std::cin.get();

    return status;
}