# Largest Rectangle in Histogram

Hard

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

### Example 1:

<p align = "center">
    <img src = "image/largest_rectangle_in_histogram_0.jpg">
</p>

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

### Example 2:

<p align = "center">
    <img src = "image/largest_rectangle_in_histogram_1.jpg">
</p>

Input: heights = [2,4]
Output: 4

### Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104

### Solution:
- define stack `st` to store the id of heights 
- invariant of stack: `heights[id]` is in increasing order
- `i` is from 0 to `n`
- if stack is empty
    - push `i` into stack
- else
    - if `i == n height = 0` 
        - trigger the calculation of area if stack is not empty when `i = n - 1`
    - else `height = heights[i]`
    - if `heights[st.top()] >= height`
        - height of interest is `st.top()` 
        - pop stack
        - width of interest is `i - st.top() - 1`
        - area of interest is height of interest * width of interst
        - save max area
        - continue until if condition is not satisfied
    - else
        - push `i` into stack
