#include "common.h"

static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

#pragma GCC optimize("Ofast")
class Solution
{
public:
    constexpr inline bool isPalindrome(const std::string& s) const
    {
        int begin = 0;
        int end = s.size() - 1;

        while (begin < end)
        {
            if (s[begin++] != s[end--])
                return false;
        }

        return true;
    }

    constexpr inline bool isOdd(int end, int begin) const
    {
        return ((end - begin) & 1) == 1;
    }

    std::string longestPalindrome(std::string s) const
    {
        int begin = 0;
        int end = begin;

        std::string tmp;
        tmp.reserve(s.size());

        std::string longest;

        while (begin < s.size())
        {
            if (end == s.size())
            {
                tmp.clear();
                ++begin;
                end = begin;
                continue;
            }

            tmp.push_back(s[end++]);
            if (isPalindrome(tmp))
                longest = longest.size() < tmp.size() ? tmp : longest;
        }
        return longest;
    }
};

TEST(p5, Simple)
{
    Solution s;

    ASSERT_EQ(s.longestPalindrome("babad"), "bab");
    ASSERT_EQ(s.longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(s.longestPalindrome("abcba"), "abcba");
}
