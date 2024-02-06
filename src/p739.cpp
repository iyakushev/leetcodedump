#include <iostream>
#include <fmt/core.h>

#include <vector>

class Solution {
public:
    Solution() { m_days.reserve(1000); }
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        m_days.clear();
        m_stack.clear();
        m_stack.resize(temperatures.size());
        m_days.resize(temperatures.size());

        for ( size_t idx = 0; idx < temperatures.size(); ++idx )
        {
            int temp = temperatures[idx];

            while ( m_stack.size() && temp > temperatures[m_stack.back()] )
            {
                auto s_idx = m_stack.back();
                m_days[s_idx] = idx - s_idx;
                m_stack.pop_back();
            }

            m_stack.push_back(idx);
        }

        return m_days;
    }

    std::vector<int> m_days;
    std::vector<int> m_stack;
};


#include <gtest/gtest.h>

TEST ( p739, Sample1 )
{
    Solution s;
    std::vector<int> data = {73,74,75,71,69,72,76,73};
    std::vector<int> expected = {1,1,4,2,1,1,0,0};
    ASSERT_EQ(expected, s.dailyTemperatures(data));
}
