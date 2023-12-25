# 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

### Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

### Constraints:

- 1 <= intervals.length <= 104
- intervals[i].length == 2
- 0 <= starti <= endi <= 104

### Solution
- 将intervals中的interval按照start从小到大排列
- 将intervals[0]插入result中
- 如果result[0][1] >= intervals[1][1]，说明result[0]和intervals[1]有overlap，这样更改result[0]的end值
- 如果result[0][1] < intervals[1][1]，说明result[0]和intervals[1]没有overlap，这样将intervals[1]加入到result
- 以此类推