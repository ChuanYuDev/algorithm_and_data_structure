# Two Sum
Easy

## Description
Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

## Example
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].

### Solution
- create a unordered map with key `a[i]` and value `i`
- tranverse `nums`
- if `target - num` has already existed in the map
    - return corresponding index 
- else
    - insert the `num` and its index into map