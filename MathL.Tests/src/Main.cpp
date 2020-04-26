#include <iostream>

#include <gtest/gtest.h>


int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << "gtest!" << std::endl;

    int status = RUN_ALL_TESTS();

    std::cin.get();

    return status;
}

TEST(gtestTest, Works)
{
    ASSERT_TRUE(false, "gtest doesnt work!");
}

TEST(gtestTest, Other)
{
    ASSERT_TRUE(true, "gtest doesnt work!");
}