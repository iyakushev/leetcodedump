#include "common.h"
#include <algorithm>


class Solution
{
private:
inline int fact(int n)
{
    int r = 1;
    while (n) r *= n--;
    return r;
}

void helper(const std::vector<int>& nums)
{
    if (m_temp.size() == nums.size())
    {
        m_result[m_index++] = m_temp;
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (std::find(m_temp.cbegin(), m_temp.cend(), nums[i]) != m_temp.cend()) continue;
        m_temp.push_back(nums[i]);
        helper(nums);
        m_temp.pop_back();
    }
}

public:
std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
    m_result.clear();
    m_result.resize(fact(nums.size()));

    m_index = 0;
    helper(nums);

    return m_result;
}

int m_index;
std::vector<int> m_temp;
std::vector<std::vector<int>> m_result;
};


TEST ( p46, Simple )
{
    Solution s;
    std::vector<std::vector<int>> r {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    std::vector<int> in{1, 2, 3};
    ASSERT_EQ(s.permute(in), r);
}
