#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

#pragma GCC optimize("Ofast")
class Solution {
public:

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        result.clear();
        std::sort(nums.begin(), nums.end());

        if (nums.size() == 3)
            return (nums[0] + nums[1] + nums[2] == 0) ? std::vector<std::vector<int>>{nums} : result;

        for (auto i = 0; i < nums.size(); ++i)
        {
            if ( nums[i] > 0 )
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            auto low = i + 1; auto high = nums.size() - 1;
            int partial_sum = 0;
            while (low < high)
            {
                partial_sum = nums[i] + nums[low] + nums[high];
                if ( partial_sum < 0 )
                    ++low;
                else if ( partial_sum > 0 )
                    --high;
                else
                {
                    result.push_back(std::move(std::vector<int>{nums[i], nums[low], nums[high]}));
                    std::pair<int, int> last_result {nums[low], nums[high]};
                    while (low < high && last_result.first == nums[low])
                        ++low;
                    while (low < high && last_result.second == nums[high])
                        --high;
                }
            }
        }

        return result;
    }

    std::vector<std::vector<int>> result;
};


TEST ( p15, simple )
{
    Solution s;

    std::vector<int> v1 = {0,0,0};
    std::vector<std::vector<int>> r1 = {{0,0,0}};

    std::vector<int> v2 = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> r2 = {{-1,-1,2}, {-1,0,1}};

    std::vector<int> v3 = {0, 1, 1};
    std::vector<std::vector<int>> r3;

    ASSERT_EQ(s.threeSum(v1), r1);
    ASSERT_EQ(s.threeSum(v2), r2);
    ASSERT_EQ(s.threeSum(v3), r3);
}
