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
    inline bool is_palindrome(const std::string &s)
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

    constexpr inline static bool is_odd(int end, int begin)
    {
        return ((end - begin) & 1) == 1;
    }

    int countSubstrings(std::string s)
    {
        std::string tmp;
        tmp.reserve(s.size() + 1);

        int begin = 0;
        int end = 0;
        int cnt = 0;

        while (begin < s.size())
        {
            if (s.size() == end)
            {
                tmp.clear();
                ++begin;
                end = begin;
                continue;
            }

            tmp.push_back(s[end++]);

            if (is_palindrome(tmp))
                ++cnt;
        }
        return cnt;
    }
};

TEST(p647, Palindrome)
{
    Solution s;

    ASSERT_TRUE(s.is_palindrome("a"));
    ASSERT_TRUE(s.is_palindrome("aa"));
    ASSERT_TRUE(s.is_palindrome("aba"));
    ASSERT_TRUE(s.is_palindrome("bab"));
    ASSERT_TRUE(s.is_palindrome("bbbbbbbbbbb"));

    ASSERT_FALSE(s.is_palindrome("baba"));
    ASSERT_FALSE(s.is_palindrome("aaab"));
}

TEST(p647, Simple)
{
    Solution s;

    ASSERT_EQ(1, s.countSubstrings("a"));
    ASSERT_EQ(6, s.countSubstrings("aaa"));
    ASSERT_EQ(6, s.countSubstrings("baba"));
    ASSERT_EQ(4, s.countSubstrings("aba"));
    ASSERT_EQ(9, s.countSubstrings("babab"));
    ASSERT_EQ(17, s.countSubstrings("itsbeenalongtime"));
    ASSERT_EQ(64, s.countSubstrings("bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb"));
}
