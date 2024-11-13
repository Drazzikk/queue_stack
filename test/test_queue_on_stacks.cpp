#include "gtest.h"
#include "stack_queue.h"

TEST(QueueOnStacks, default_constructor)
{
    ASSERT_NO_THROW(QueueOnStacks<int> QoS);
}

TEST(QueueOnStacks, full_check)
{
    QueueOnStacks<int> QoS;
    EXPECT_FALSE(QoS.Full());
}

TEST(QueueOnStacks, get_size)
{
    QueueOnStacks<int> QoS;
    QoS.push(1);
    QoS.push(2);
    EXPECT_EQ(QoS.size(), 2);
}

TEST(QueueOnStacks, get_capacity)
{
    Stack<int> QoS;
    EXPECT_EQ(QoS.getCapacity(), 2);
}

TEST(QueueOnStacks, push_and_front) {
    QueueOnStacks<int> QoS;
    QoS.push(1);
    QoS.push(2);
    EXPECT_EQ(QoS.front(), 1);
}

TEST(QueueOnStacks, pop) {
    QueueOnStacks<int> QoS;
    QoS.push(1);
    QoS.push(2);
    QoS.pop();
    EXPECT_EQ(QoS.front(), 2);
}

TEST(QueueOnStacks, get_back)
{
    QueueOnStacks<int> QoS;
    QoS.push(1);
    QoS.push(2);
    EXPECT_EQ(2, QoS.back());
}

TEST(QueueOnStacks, empty_check) {
    QueueOnStacks<int> QoS;
    EXPECT_TRUE(QoS.Empty());
}