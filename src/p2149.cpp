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
    std::vector<int> rearrangeArray(std::vector<int> &nums)
    {
        std::vector<int> result(nums.size(), 0);

        int pos = 0;
        int neg = 1;

        for (int idx = 0; idx < nums.size(); ++idx)
        {
            if (nums[idx] > 0)
            {
                result[pos] = nums[idx];
                pos += 2;
            }
            else
            {
                result[neg] = nums[idx];
                neg += 2;
            }
        }

        return result;
    }
};

TEST(p2149, Simple)
{
    Solution s;
    std::vector<int> in{3, 1, -2, -5, 2, -4};
    std::vector<int> out{3, -2, 1, -5, 2, -4};

    ASSERT_EQ(s.rearrangeArray(in), out);
}

TEST(p2149, Same)
{
    Solution s;
    std::vector<int> in{-1, 1};
    std::vector<int> out{1, -1};

    ASSERT_EQ(s.rearrangeArray(in), out);
}

TEST(p2149, Long)
{
    Solution s;

    std::vector<int> in{28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31};
    std::vector<int> out{28, -41, 22, -8, 46, -37, 35, -9, 18, -6, 19, -26, 15, -37, 14, -10, 31, -9};

    ASSERT_EQ(s.rearrangeArray(in), out);
}

TEST(p2149, Other)
{
    Solution s;

    std::vector<int> in{3, -15, -45, -38, 2, -34, -16, 3, 47, 41, 46, -10, 48, -13, 43, -40};
    std::vector<int> out{3, -15, 2, -45, 3, -38, 47, -34, 41, -16, 46, -10, 48, -13, 43, -40};

    ASSERT_EQ(s.rearrangeArray(in), out);
}
