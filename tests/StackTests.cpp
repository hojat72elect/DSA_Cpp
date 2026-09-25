#include <gtest/gtest.h>
#include "Stack.hpp"

TEST(StackTest, InitiallyEmpty) {
    Stack<int> sut;
    EXPECT_TRUE(sut.isEmpty());
    EXPECT_EQ(sut.length(), 0);
}

TEST(StackTest, PushIncreasesLength) {
    Stack<int> sut;
    sut.push(10);
    EXPECT_FALSE(sut.isEmpty());
    EXPECT_EQ(sut.length(), 1);

    sut.push(20);
    EXPECT_EQ(sut.length(), 2);
}
