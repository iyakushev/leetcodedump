#include "common.h"

using Meetings = std::vector<std::vector<int>>;
using Interval = std::pair<int, int>;
static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

#pragma GCC optimize("Ofast")
struct CompareBooking
{
    constexpr bool operator()(const Interval &in1, const Interval &in2) const
    {
        return in1.first < in2.first && in1.second < in2.first;
    }
};

#pragma GCC optimize("Ofast")
class Solution
{
public:
    struct Room
    {
        int num_meetings;
        int booked_till;

        Room() : num_meetings(0), booked_till(0)
        {
        }

        void occupy(int end_time)
        {
            booked_till = end_time;
            ++num_meetings;
        }

        inline bool is_vacant(int begin_time) const
        {
            return begin_time >= booked_till;
        }
    };

    bool did_occupy_room(int begin_time, int end_time)
    {
        for (auto &room : m_rooms)
        {
            if (room.is_vacant(begin_time))
            {
                room.occupy(end_time);
                return true;
            }
        }
        return false;
    }

    int mostBooked(int n, Meetings &meetings)
    {
        m_rooms.clear();
        m_rooms.resize(n);
        std::priority_queue<Interval, std::vector<Interval>, CompareBooking> delayed;

        for (auto &meeting : meetings)
        {
            if (did_occupy_room(meeting[0], meeting[1]))
                continue;
            delayed.push({meeting[0], meeting[1]});
        }

        while ( !delayed.empty() )
        {
            auto delayed = delayed.top();
        }

        int most_visited = 0;
        for (int idx = 0; idx < m_rooms.size(); ++idx)
            most_visited = m_rooms[most_visited].num_meetings > m_rooms[idx].num_meetings ? most_visited : idx;

        return most_visited;
    }
    std::vector<Room> m_rooms;
};

TEST(p2402, Simple)
{
    Solution s;

    Meetings in{{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    ASSERT_EQ(s.mostBooked(2, in), 0);
}
