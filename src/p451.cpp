#include "common.h"

constexpr int BEGIN_UPPER_CH = 0;
constexpr int BEGIN_LOWER_CH = 26;
constexpr int BEGIN_NUMBER_CH = 52;

constexpr int NUMBER_OF_CH = 62;

class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::array<int, NUMBER_OF_CH> freq;
        freq.fill(0);

        // fill frequencies
        for (char c : s)
        {
            if (c < 'A')
                freq[52 + c - '0']++;
            else if (c <= 'Z')
                freq[c - 'A']++;
            else
                freq[26 + c - 'a']++;
        }

        std::vector<std::pair<int, char>> result;

        for (int i = BEGIN_UPPER_CH; i < BEGIN_LOWER_CH; ++i)
        {
            if (freq[i] != 0)
                result.emplace_back(freq[i], char(i + 'A'));
        }

        for (int i = BEGIN_LOWER_CH; i < BEGIN_NUMBER_CH; ++i)
        {
            if (freq[i] != 0)
                result.emplace_back(freq[i], char((i - BEGIN_LOWER_CH) + 'a'));
        }

        for (int i = BEGIN_NUMBER_CH; i < freq.size(); ++i)
        {
            if (freq[i] != 0)
                result.emplace_back(freq[i], char((i - BEGIN_NUMBER_CH) + '0'));
        }

        std::sort(result.begin(), result.end(), std::greater<std::pair<int, char>>());

        std::string answer;
        for (auto [fr, ch] : result)
            while (fr--)
                answer.push_back(ch);
        return answer;
    }
};

TEST(p451, Simple)
{
    Solution s;

    ASSERT_EQ("eetr", s.frequencySort("tree"));
    ASSERT_EQ("cccaaa", s.frequencySort("cccaaa"));
    ASSERT_EQ("bbaA", s.frequencySort("Aabb"));
}
