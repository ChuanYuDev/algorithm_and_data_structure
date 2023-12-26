#ifndef LEETCODE_84_HPP_
#define LEETCODE_84_HPP_

#include <vector>
#include <stack>

namespace leetcode
{

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int width = 0, largest_area = 0, height = 0, calculate_height = 0, n = heights.size();
        std::stack<int> st;

        for (int i = 0; i <= n; ++i)
        {
            height = (i == n)? 0: heights[i];

            while(!st.empty() && heights[st.top()] >= height)
            {
                calculate_height = heights[st.top()];
                st.pop();
                width = (st.empty())? i: i - st.top() - 1;
                largest_area = std::max(largest_area, calculate_height * width);
            }

            st.push(i);
        }

        return largest_area;
    }
};

class Solution1 {
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        std::vector<int> min_heights;     
        min_heights.resize(heights.size());

        int area = 0, largest_area = 0, min_height = 0;

        for (std::size_t i = 0; i < heights.size(); ++i)
        {
            for (std::size_t j = 0; j <= i; ++j)
            {
                min_height = (j == i)? heights[i]:std::min(min_heights[j], heights[i]); 
                min_heights[j] = min_height;

                area = min_height * (i - j + 1);
                if (area > largest_area)
                    largest_area = area; 
            }
        }

        return largest_area;
    }
};

} // namespace leetcode

#endif // LEETCODE_84_HPP_