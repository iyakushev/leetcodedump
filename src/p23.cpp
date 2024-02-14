#include "common.h"
#include <queue>

struct ListNode
{
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }

    int val;
    ListNode *next;
};

static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

template <typename T> struct compare_nodes
{
    constexpr bool operator()(T *left, T *right)
    {
        return left->val > right->val;
    }
};

#pragma GCC optimize("Ofast")
class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        std::priority_queue<ListNode *, std::vector<ListNode *>, compare_nodes<ListNode>> pq;
        ListNode *first = nullptr;

        for (auto lst : lists)
            while (lst)
            {
                pq.emplace(lst);
                lst = lst->next;
            }

        if (!pq.empty())
        {
            first = pq.top();
            pq.pop();
        }

        ListNode *tmp = first;
        while (!pq.empty())
        {
            ListNode *new_node = pq.top();
            tmp->next = new_node;
            tmp = new_node;
            pq.pop();
        }
        tmp->next = nullptr;

        return first;
    }
};

ListNode create_list(std::initializer_list<int> values)
{
    if (values.begin() == values.end())
        return {};

    ListNode begin = ListNode(*values.begin());
    ListNode *tmp = &begin;

    bool inited = false;
    std::cout << fmt::format("{} ", tmp->val);
    for (auto value : values)
    {
        if (!inited)
        {
            inited = true;
            continue;
        }
        ListNode *n = new ListNode(value);
        std::cout << fmt::format("-> {} ", n->val);
        tmp->next = n;
        tmp = n;
    }
    std::cout << std::endl;
    return begin;
}

TEST(p23, Simple)
{
    Solution s;

    auto node1 = create_list({1, 4, 5});
    auto node2 = create_list({1, 3, 4});
    auto node3 = create_list({2, 6});

    std::vector<ListNode *> in{&node1, &node2, &node3};

    auto result_node = create_list({1, 1, 2, 3, 4, 4, 5, 6});

    auto merged = s.mergeKLists(in);

    auto x = merged;
    auto r = &result_node;
    while (x)
    {
        ASSERT_EQ(x->val, r->val);
        r = r->next;
        x = x->next;
    }
}

TEST(p23, useAfterFree)
{
    Solution s;

    auto l1 = create_list({-1, -1, -1});
    auto l2 = create_list({-2, -2, -1});

    std::vector<ListNode *> in{&l1, &l2};
    auto res = create_list({-2, -2, -1, -1, -1, -1});
    auto merged = s.mergeKLists(in);

    auto x = merged;
    auto r = &res;
    while (x)
    {
        ASSERT_EQ(x->val, r->val);
        r = r->next;
        x = x->next;
    }
}

TEST(p23, empty)
{
    Solution s;
    std::vector<ListNode *> x{};
    ASSERT_EQ(s.mergeKLists(x), nullptr);
}

TEST(p23, emptyempty)
{
    Solution s;
    ListNode *l = nullptr;
    std::vector<ListNode *> x{l};
    ASSERT_EQ(s.mergeKLists(x), nullptr);
}
