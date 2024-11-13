#include "gtest.h"
#include "stack_queue.h"

TEST(Stack, default_constructor)
{
    ASSERT_NO_THROW(Stack<int> stack);
}

TEST(Stack, full_check)
{
    Stack<int> stack;
    EXPECT_FALSE(stack.Full());
}

TEST(Stack, get_size)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.size(), 2);
}

TEST(Stack, get_capacity)
{
    Stack<int> stack;
    EXPECT_EQ(stack.getCapacity(), 2);
}

TEST(Stack, push_and_top) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);
}

TEST(Stack, pop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
}

TEST(Stack, empty_check) {
    Stack<int> stack;
    EXPECT_TRUE(stack.Empty());
    stack.push(1);
    EXPECT_FALSE(stack.Empty());
}