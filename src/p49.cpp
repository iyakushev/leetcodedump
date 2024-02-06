#include "common.h"


using SolutionT = std::vector<std::vector<std::string>>;


namespace
{
constexpr inline bool xstrcmp(const std::string& str1, const std::string& str2)
{
    if (str1.size() != str2.size())
        return false;

    int result = 0;
    for (int idx = 0; idx < str1.size(); ++idx)
        result ^= str1[idx] ^ str2[idx];
    return result == 0;
}
}

class Solution
{
public:
    SolutionT groupAnagrams(std::vector<std::string>& strs)
    {
        SolutionT result;

        m_store["asd"] = {};
        m_store["abc"] = {};

        for (const auto& str : strs)
        {
            auto key = str;
            std::sort(key.begin(), key.end());

            m_store[key].push_back(str);
        }

        for (auto& [_, v] : m_store)
            result.emplace_back(std::move(v));
        return result;
    }

std::unordered_map<std::string, std::vector<std::string>> m_store;
};


TEST ( p49, Simple )
{
    Solution s;

    std::vector<std::string> in = {"eat","tea","tan","ate","nat","bat"};

    auto result = s.groupAnagrams(in);

    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"bat"}) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"tan", "nat"}) != result.end());
}


TEST ( p49, Empty )
{
    Solution s;

    std::vector<std::string> in = {"", "b", ""};

    auto result = s.groupAnagrams(in);

    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"", ""}) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"b"}) != result.end());
}


TEST ( p49, Xor )
{
    Solution s;

    std::vector<std::string> in = {"abbbbbbbbbbb","aaaaaaaaaaab"};

    auto result = s.groupAnagrams(in);

    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"abbbbbbbbbbb"}) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), std::vector<std::string>{"aaaaaaaaaaab"}) != result.end());
}
