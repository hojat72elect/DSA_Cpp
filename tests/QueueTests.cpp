#include <gtest/gtest.h>
#include "Queue.hpp"

class QueueTests : public ::testing::Test {
protected:
    Queue<int> intQueue;
    Queue<std::string> stringQueue;
};

TEST_F(QueueTests, initiallyEmptyQueue) {
    EXPECT_TRUE(intQueue.isEmpty());
    EXPECT_EQ(intQueue.length(), 0);
}

TEST_F(QueueTests, enqueuingIntoAQueue) {
    intQueue.enqueue(12);
    EXPECT_FALSE(intQueue.isEmpty());
    EXPECT_EQ(intQueue.length(), 1);

    intQueue.enqueue(23);
    EXPECT_EQ(intQueue.length(), 2);
}

TEST_F(QueueTests, peekingAtFrontElement) {
    intQueue.enqueue(46);
    EXPECT_EQ(intQueue.peekFront(), 46);
    EXPECT_EQ(intQueue.length(), 1);
    EXPECT_FALSE(intQueue.isEmpty());
}

TEST_F(QueueTests, peekOnEmptyQueueThrowsException) {
    EXPECT_THROW(intQueue.peekFront(), std::out_of_range);
}

TEST_F(QueueTests, dequeuingAQueueWorksInFIFOOrder) {
    intQueue.enqueue(45);
    intQueue.enqueue(13);
    intQueue.enqueue(67);

    EXPECT_EQ(intQueue.dequeue(), 45);
    EXPECT_EQ(intQueue.dequeue(), 13);
    EXPECT_EQ(intQueue.dequeue(), 67);
    EXPECT_EQ(intQueue.length(), 0);
    EXPECT_TRUE(intQueue.isEmpty());
}

TEST_F(QueueTests, dequeueOnEmptyQueueThrowsException) {
    EXPECT_THROW(intQueue.dequeue(), std::out_of_range);
}

TEST_F(QueueTests, clearEmptiesAQueue) {
    intQueue.enqueue(1);
    intQueue.enqueue(2);

    EXPECT_EQ(intQueue.length(), 2);
    EXPECT_FALSE(intQueue.isEmpty());

    intQueue.clear();

    EXPECT_EQ(intQueue.length(), 0);
    EXPECT_TRUE(intQueue.isEmpty());
}
