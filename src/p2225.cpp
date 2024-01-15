#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

#include <map>


class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
    {
        m_losing_freq.clear();

        std::vector<int> winners;
        std::vector<int> winners_with_loss;

        for (const auto& match : matches)
        {
            if (!m_losing_freq.contains(match[0]))
                m_losing_freq[match[0]] = 0;
            m_losing_freq[match[1]]++;
        }

        winners.reserve(m_losing_freq.size());
        winners_with_loss.reserve(m_losing_freq.size());

        for (auto [player, freq] : m_losing_freq)
        {
            if (freq == 0)
                winners.emplace_back(player);
            else if (freq == 1)
                winners_with_loss.emplace_back(player);
        }

        return { std::move(winners), std::move(winners_with_loss) };
    }

    std::map<int, int> m_losing_freq;
};


TEST ( p2225, simple )
{
    Solution s;
    std::vector<std::vector<int>> v1 = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    std::vector<std::vector<int>> r1 = {{1,2,10},{4,5,7,8}};

    ASSERT_EQ(s.findWinners(v1), r1);
}
