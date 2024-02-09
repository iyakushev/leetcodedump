#include "common.h"

class Solution
{
public:
    int numSquares(int n)
    {
        m_memo.reserve(n);

        int top = std::sqrt(n);
        int result = INT_MAX;

        while (top--)
            result = std::min(result, solver(n));
        return result;
    }

    int solver(int remainder)
    {
        if (remainder < 0)
            return INT_MAX;

        if (remainder == 0)
            return 0;

        if (m_memo.contains(remainder))
            return m_memo[remainder];

        int result = INT_MAX;
        for (int i = 1; i <= std::sqrt(remainder); ++i)
            result = std::min(result, 1 + solver(remainder - i * i));
        return m_memo[remainder] = result;
    }

    std::unordered_map<int, int> m_memo;
};

TEST(p279, Simple)
{
    Solution s;
    ASSERT_EQ(2, s.numSquares(13));
    ASSERT_EQ(3, s.numSquares(12));
    ASSERT_EQ(2, s.numSquares(10));
    ASSERT_EQ(3, s.numSquares(43));
    ASSERT_EQ(3, s.numSquares(48));
}
