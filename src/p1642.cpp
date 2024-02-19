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
    template <typename It> constexpr int make_a_move(It current, It end, int bricks, int ladders, int n_steps)
    {
        It next = current + 1;

        if (next == end)
            return n_steps;

        if (*current >= *next)
            return make_a_move(next, end, bricks, ladders, n_steps + 1);

        int diff = std::abs(*current - *next);

        int temp = 0;
        if (bricks >= diff)
            temp = make_a_move(next, end, bricks - diff, ladders, n_steps + 1);

        if (ladders > 0)
            temp = std::max(temp, make_a_move(next, end, bricks, ladders - 1, n_steps + 1));

        return std::max(temp, n_steps);
    }


    int furthestBuilding(std::vector<int> &heights, int bricks, int ladders)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int idx = 0; idx < heights.size() - 1; ++idx)
        {
            int diff = heights[idx + 1] - heights[idx];
            if (diff <= 0) continue;
            pq.push(diff);
            if (pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return idx;
        }
        return heights.size() - 1;
    }
};

TEST(p1642, Simple)
{
    Solution s;

    std::vector<int> in{4, 2, 7, 6, 9, 14, 12};
    ASSERT_EQ(s.furthestBuilding(in, 5, 1), 4);

    std::vector<int> in2{4, 12, 2, 7, 3, 18, 20, 3, 19};
    ASSERT_EQ(s.furthestBuilding(in2, 10, 2), 7);

    std::vector<int> in3{14, 3, 19, 3};
    ASSERT_EQ(s.furthestBuilding(in3, 17, 0), 3);
}
