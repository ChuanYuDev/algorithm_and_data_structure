# Merge Intervals

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
- sort `intervals` element based on start
- insert `intervals[0]` into `result`
- traverse `intervals`
- if `result[0][1] >= intervals[1][1]`
    - `result[0]` and `intervals[1]` overlap，change `result[0]` end value
- else
    - `result[0]` and `intervals[1]` do not overlap，insert `result[1]` into `result`