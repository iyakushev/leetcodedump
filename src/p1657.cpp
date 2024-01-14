#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include <array>

class Solution {
public:
    [[nodiscard]] static inline std::array<int, 26> str_to_arr(const std::string& word, std::array<bool, 26>& cache)
    {
        std::array<int, 26> acc;
        acc.fill(0);

        #pragma clang loop unroll(full)
        for (char chr : word)
        {
            auto offset = chr - 'a';
            acc[offset] += 1;
            cache[offset] = 1;
        }

        return acc;
    }

    bool closeStrings(const std::string& word1, const std::string& word2) {
        if (word1.size() != word2.size())
            return false;
        m_cache1.fill(0);
        m_cache2.fill(0);

        auto freq1 = str_to_arr(word1, m_cache1);
        auto freq2 = str_to_arr(word2, m_cache2);
        if (m_cache1 != m_cache2)
            return false;

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }

    std::array<bool, 26> m_cache1;
    std::array<bool, 26> m_cache2;
};


TEST ( p1657, simple )
{
    Solution s;
    ASSERT_TRUE(s.closeStrings("abc", "cba"));
    ASSERT_FALSE(s.closeStrings("a", "aa"));
    ASSERT_TRUE(s.closeStrings("cabbba", "abbccc"));
    ASSERT_FALSE(s.closeStrings("abbzzca", "babzzcz"));
}
