#include <gtest/gtest.h>
#include "Stack.hpp"


class StackTests : public ::testing::Test {
protected:
    Stack<int> intStack;
    Stack<std::string> stringStack;
};

TEST_F(StackTests, initiallyEmptyStack) {
    EXPECT_TRUE(intStack.isEmpty());
    EXPECT_EQ(intStack.length(), 0);
}

TEST_F(StackTests, pushingIntoAnStack) {
    intStack.push(12);
    EXPECT_FALSE(intStack.isEmpty());
    EXPECT_EQ(intStack.length(), 1);

    intStack.push(23);
    EXPECT_EQ(intStack.length(), 2);
}

TEST_F(StackTests, peekingIntoAnElement) {
    intStack.push(46);
    EXPECT_EQ(intStack.peek(), 46);
    EXPECT_EQ(intStack.length(), 1);
    EXPECT_FALSE(intStack.isEmpty());
}

TEST_F(StackTests, peekOnEmptyStackThrowsException) {
    EXPECT_THROW(intStack.peek(), std::out_of_range);
}

TEST_F(StackTests, poppingAStackWorksInLIFOOrder) {
    intStack.push(45);
    intStack.push(13);
    intStack.push(67);

    EXPECT_EQ(intStack.pop(), 67);
    EXPECT_EQ(intStack.pop(), 13);
    EXPECT_EQ(intStack.pop(), 45);
    EXPECT_EQ(intStack.length(), 0);
    EXPECT_TRUE(intStack.isEmpty());
}

TEST_F(StackTests, popOnEmptyStackThrowsException) {
    EXPECT_THROW(intStack.pop(), std::out_of_range);
}

TEST_F(StackTests, clearEmptiesAStack) {
    intStack.push(1);
    intStack.push(2);

    EXPECT_EQ(intStack.length(), 2);
    EXPECT_FALSE(intStack.isEmpty());

    intStack.clear();

    EXPECT_EQ(intStack.length(), 0);
    EXPECT_TRUE(intStack.isEmpty());
}
