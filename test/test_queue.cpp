#include "gtest.h"
#include "stack_queue.h"

TEST(Queue, default_constructor)
{
    ASSERT_NO_THROW(Queue<int> queue);
}

TEST(Queue, full_check)
{
    Queue<int> queue;
    EXPECT_FALSE(queue.Full());
}

TEST(Queue, get_size)
{
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.size(), 2);
}

TEST(Queue, get_capacity)
{
    Queue<int> queue;
    EXPECT_EQ(queue.getCapacity(), 2);
}

TEST(Queue, push_and_get_front) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.getFront(), 1);
}

TEST(Queue, pop) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.pop();
    EXPECT_EQ(queue.getFront(), 2);
}

TEST(Queue, empty_check) {
    Queue<int> queue;
    EXPECT_TRUE(queue.Empty());
}

TEST(Queue, push_and_pop) {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_NO_THROW(queue.pop());
    EXPECT_EQ(queue.getFront(), 2); 

    EXPECT_NO_THROW(queue.pop());
    EXPECT_TRUE(queue.Empty()); 
}