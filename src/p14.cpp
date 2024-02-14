#include "common.h"

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.empty())
            return "";

        std::string common = strs[0];

        for (const auto &str : strs)
        {
            if (str.empty() || str[0] != common[0])
                return "";

            if (str.size() < common.size())
                common.erase(str.size(), common.size() - str.size());

            for (int idx = 0; idx < common.size(); ++idx)
                if (str[idx] != common[idx])
                    common.erase(idx, common.size());
        }

        return common;
    }
};

TEST(p14, Simple)
{
    Solution s;

    std::vector<std::string> in{"flower", "flora", "fly"};
    ASSERT_EQ(s.longestCommonPrefix(in), "fl");

    std::vector<std::string> in2{"flower", "boar", "car"};
    ASSERT_EQ(s.longestCommonPrefix(in2), "");
}
