#include <vector>
#include <iostream>

class Solution
{
public:
    int longestSubarray(std::vector<int>& nums)
    {
        int size = nums.size();

        // x & y > x if x > y

        // x & y == x if and only if x == y
        //          x: 100111
        //          y: 100111 
        //      x & y: 100111

        // Subarray with max_and_value will always contain max element 
        //      [a, b, ... max, ...] <= [max]

        // max_and_value is max(nums)
        // Subarray is a contiguous sequence of elements within an array

        // Get longest length of continuous elements which equal max
        int max = 0;
        int max_length = 0;
        int length = 0;
        bool is_element_max = false;

        // Get max first
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (nums[i] < max)
            {
                is_element_max = false;

                max_length = length > max_length? length: max_length;
            }

            if (nums[i] == max)
            {
                // Check previous element == max
                if (is_element_max)
                    length++;
                else
                    length = 1;
                
                is_element_max = true;
            }
        }

        if (is_element_max)
            max_length = length > max_length? length: max_length;

        return max_length;
    }
};

class SolutionSlow
{
public:
    int longestSubarray(std::vector<int>& nums)
    {
        // andValue: bitwise AND operation on the subarray 

        // max_and_value: Maximum value of the bitwise AND of any subarray
        int max_and_value = 0;
        // max_length: longest subarray with max_and_value
        int max_length = 0;

        int and_value = 0;
        int length = 0;

        int size = nums.size();
        // Loop nums to get all the subarrays
        // Subarray is a contiguous sequence of elements within an array

        // 1, 2, 3, 4
        // i: 0 j: 0 1 2 3 4
        //      1
        //      1 2
        //      1 2 3
        //      1 2 3 4

        // i: 1 j: 1 2 3 4
        //      2
        //      2 3
        //      2 3 4

        // Complexity: O(n^2) which is too slow
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                // Subarray is nums[i ... j]
                //      Length: j - i + 1
                length = j - i + 1;

                // When we fix the start of the subarray, increase end of the subarray
                //      andValue(nums[start, end + 1]) = andValue(nums[start, end]) & nums[end + 1]

                if (i == j)
                    and_value = nums[j];
                else
                    and_value &= nums[j];

                // if andValue(subarray) == max_and_value
                //      max_length: assign it to the longer length of subarray 
                if (and_value == max_and_value)
                {
                    max_length = max_length > length ? max_length : length;
                    continue;
                }

                // if andValue(subarray) > max_and_value
                //      max_and_value is replaced
                //      max_length is also replaced
                if (and_value > max_and_value)
                {
                    max_and_value = and_value;
                    max_length = length;
                    continue;
                }
            }
        }

        return max_length;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums;
    int max_length;

    // Example 1
    nums = {1, 2, 3, 3, 2, 2};
    max_length = solution.longestSubarray(nums);

    std::cout << "Answer: 2" << std::endl;
    std::cout << "Output: " << max_length << std::endl;

    // Example 2
    nums = {1, 2, 3, 4};
    max_length = solution.longestSubarray(nums);

    std::cout << "Answer: 1" << std::endl;
    std::cout << "Output: " << max_length << std::endl;
    return 0;
}