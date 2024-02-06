#include <iostream>
#include <fmt/core.h>

#include <vector>

class StockSpanner {
public:

    struct Record { size_t idx; int price; };

    StockSpanner()
    {
        m_stack.resize(1000);
        m_index = 0;
    }

    int next(int price)
    {
        while (m_stack.size() && price >= m_stack.back().price)
            m_stack.pop_back();

        m_stack.emplace_back(++m_index, price);

        return m_stack.size() > 1 ? m_stack.back().idx - m_stack[m_stack.size() - 2].idx : m_index;
    }

    size_t m_index;
    std::vector<Record> m_stack;
};


#include <gtest/gtest.h>

TEST ( p901, Simple )
{
    StockSpanner s;
    ASSERT_EQ(s.next(100), 1);
    ASSERT_EQ(s.next(80), 1);
    ASSERT_EQ(s.next(60), 1);
    ASSERT_EQ(s.next(70), 2);
    ASSERT_EQ(s.next(60), 1);
    ASSERT_EQ(s.next(75), 4);
    ASSERT_EQ(s.next(85), 6);
}
