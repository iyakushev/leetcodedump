#include <iostream>
#include <fmt/core.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for (size_t idx = 0; idx < nums.size(); idx+=3)
        {
            if (idx + 2 > nums.size())
                break;

            if (nums[idx+2] - nums[idx] > k)
                return {};

            result.push_back(std::move(std::vector<int>{nums[idx], nums[idx+1], nums[idx+2]}));
        }

        return result;
    }
};


#include <gtest/gtest.h>

TEST (p2966, Simple)
{
    Solution s;

    std::vector<int> data = {1,3,4,8,7,9,3,5,1};
    auto result = s.divideArray(data, 3);

    std::vector<std::vector<int>> expected = {{1,1,3}, {3,4,5}, {7,8,9}};

    ASSERT_EQ(result, expected);
}
