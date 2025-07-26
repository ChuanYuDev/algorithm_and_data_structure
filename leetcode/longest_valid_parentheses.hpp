#ifndef LEETCODE_LONGEST_VALID_PARENTHESES_HPP_
#define LEETCODE_LONGEST_VALID_PARENTHESES_HPP_

#include <string>
#include <stack>

namespace leetcode
{
class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int size = s.size();
        std::stack<int> stk;
        int top, longest_length = 0, lengh = 0;
        
        for (int i = 0; i < size; ++i)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                if (stk.empty())
                    stk.push(i);
                else
                {
                    top = stk.top();

                    if (s[top] == '(')
                    {
                        stk.pop();

                        if (stk.empty())
                            lengh = i + 1;
                        else
                            lengh = i - stk.top();

                        if (lengh > longest_length)
                            longest_length = lengh;
                    }
                    else
                        stk.push(i);
                }
            }
        }

        return longest_length;
    }
};

} // namespace leetcode

#endif // LEETCODE_LONGEST_VALID_PARENTHESES_HPP_