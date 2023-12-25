#ifndef LEETCODE_56_MERGE_INTERVALS_HPP_
#define LEETCODE_56_MERGE_INTERVALS_HPP_

#include <vector>
#include <algorithm>
#include <iostream>

namespace leetcode
{

class Solution 
{
public:
    static bool lessVector(std::vector<int> &v0, std::vector<int> &v1)
    {
        return v0[0] < v1[0];
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) 
    {
        if (intervals.size() <= 1)
            return intervals;
        
        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), Solution::lessVector);

        result.push_back(intervals[0]);
        int last_result_id = 0;

        for (int i = 1; i < intervals.size(); ++i)
        {
            last_result_id = result.size() - 1;

            if (result[last_result_id][1] >= intervals[i][0])
            {
                result[last_result_id][1] = std::max(intervals[i][1], result[last_result_id][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

};
} // namespace leetcode

#endif // LEETCODE_56_MERGE_INTERVALS_HPP_