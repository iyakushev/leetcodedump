#include <array>

class MyQueue {
public:
    MyQueue() {
        m_stack.fill(0);
        m_tail = m_head = 0;
    }

    void push(int x) {
        m_stack[m_tail++] = x;
    }

    int pop() {
        return m_stack[m_head++];
    }

    int peek() {
        return m_stack[m_head];
    }

    bool empty() {
        return m_head == m_tail;
    }

    std::array<int, 100> m_stack;
    size_t m_head;
    size_t m_tail;
};



#include <gtest/gtest.h>


TEST ( MyQueue, test )
{
    MyQueue x;

    ASSERT_TRUE(x.empty());
    x.push(1);
    ASSERT_FALSE(x.empty());
    x.push(2);
    x.push(3);
    ASSERT_EQ(x.peek(), 1);
    ASSERT_EQ(x.pop(), 1);
    ASSERT_EQ(x.pop(), 2);
    x.push(4);
    x.push(5);
    x.push(6);
    x.push(7);
    ASSERT_EQ(x.pop(), 3);
    ASSERT_EQ(x.pop(), 4);
    ASSERT_EQ(x.pop(), 5);
    ASSERT_EQ(x.pop(), 6);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.pop(), 7);
    ASSERT_TRUE(x.empty());
}
