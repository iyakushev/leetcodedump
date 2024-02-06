#include <string>
#include <vector>


constexpr int gTOKEN_MAX_LEN = 10000;

namespace Token
{
    constexpr char kAdd = '+';
    constexpr char kMul = '*';
    constexpr char kDiv = '/';
    constexpr char kSub = '-';
}

class Solution
{
public:
    Solution() { m_stack.reserve(gTOKEN_MAX_LEN); m_ptr = 0; }

    int evalRPN(std::vector<std::string>& tokens)
    {
        int result = 0;
        for (const auto& token : tokens)
        {
            if (*token.data() >= '0' || token.size() > 1)
                result = atoi(token.data(), token.data() + token.size());
            else
                result = evaluate_op(*token.data());

            m_stack.push_back(result);
        }
        return m_stack.back();
    }


private:
    [[nodiscard]] static constexpr int atoi(const char* begin, const char* end)
    {
        int value = 0;
        int sign =  1;
        if (*begin == '-')
        {
             sign = -1;
            ++begin;
        }

        while (begin != end)
            value = (value << 1) + (value << 3) + (*begin++) - '0';
        return sign * value;
    }

    [[nodiscard]] int evaluate_op(const char op)
    {
        int second = m_stack.back();
        m_stack.pop_back();
        int first = m_stack.back();
        m_stack.pop_back();

        switch (op)
        {
            case '+': return first + second;
            case '-': return first - second;
            case '*': return first * second;
            case '/': return first / second;
        }

        return INT_MIN;
    }

    size_t m_ptr;
    std::vector<int> m_stack;
};


#include <gtest/gtest.h>

TEST ( p150, Eval )
{
    Solution s;
    std::vector<std::string> data = {"2","1","+","3","*"};
    ASSERT_EQ(s.evalRPN(data), 9);
}



TEST ( p150, Eval2 )
{
    Solution s;
    std::vector<std::string> data = {"4","13","5","/","+"};
    ASSERT_EQ(s.evalRPN(data), 6);
}


TEST ( p150, Eval3 )
{
    Solution s;
    std::vector<std::string> data = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    ASSERT_EQ(s.evalRPN(data), 22);
}


TEST ( p150, Eval4 )
{
    Solution s;
    std::vector<std::string> data = {"3", "-4", "+"};
    ASSERT_EQ(s.evalRPN(data), -1);
}
