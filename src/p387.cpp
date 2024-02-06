#include "common.h"


constexpr int ARRAY_SIZE = 26;

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        m_freq.fill(0);

        for (char ch : s)
            m_freq[ch - 'a'] += 1;

        for (int idx = 0; idx < s.size(); ++idx)
        {
            if (m_freq[s[idx] - 'a'] == 1)
                return idx;
        }

        return -1;
    }

    std::array<int, ARRAY_SIZE> m_freq;
};


TEST (p387, Simple)
{
    Solution s;
    ASSERT_EQ(s.firstUniqChar("leetcode"), 0);
    ASSERT_EQ(s.firstUniqChar("loveleetcode"), 2);
    ASSERT_EQ(s.firstUniqChar("aabb"), -1);
}
