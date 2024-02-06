#include "common.h"

class Solution
{
public:
    std::vector<uint64_t> getRow(int rowIndex)
    {
        m_res.clear();
        m_res.resize(rowIndex + 1);
        m_res[0] = 1;

        for (int idx = 1; idx < rowIndex + 1; ++idx)
            m_res[idx] = m_res[idx - 1] * (rowIndex - idx + 1) / idx;

        return m_res;
    }

    std::vector<uint64_t> m_res;
};

TEST (p119, Simple)
{
    Solution s;

    std::vector<int> r{ 1, 3, 3, 1};
    ASSERT_EQ(s.getRow(3), r);
    std::vector<int> r1 = {1};
    ASSERT_EQ(s.getRow(0), r1);
    std::vector<int> r2 = {1, 1};
    ASSERT_EQ(s.getRow(1), r2);
    std::vector<int> r4 = {1, 9, 36, 84, 126, 126, 84, 36, 9, 1};
    ASSERT_EQ(s.getRow(9), r4);
}
