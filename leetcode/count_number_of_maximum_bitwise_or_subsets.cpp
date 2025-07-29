#include <vector>
#include <iostream>

class Solution
{
public:

    int max_or_value;
    int count;
    int length;

    int countMaxOrSubsets(std::vector<int>& nums)
    {
        max_or_value = 0;
        count = 0;
        length = nums.size();

        // Get the largest bitwise OR value max_or_value of subset which is orValue(nums) 
        for (int i = 0; i < length; i++)
        {
            max_or_value |= nums[i];
        }

        enumerateAll(nums, 0, 0);

        return count;
    }

    // Enumerate all the subsets
    // 3 2 1 5
    // Empty subset
    // 3
    // Enumerate 2 1 5
    // Empty subset -> {3} 

    // 2
    // Enumerate 1 5
    // 1
    // Enumerate 5
    // 5
    void enumerateAll(std::vector<int> & nums, int start, int or_val_before_start)
    {
        // Represent subsets without remaining elements
        if (or_val_before_start == max_or_value)
            count++;

        for (int i = start; i < length; i++)
            enumerateAll(nums, i + 1, or_val_before_start | nums[i]);
    }
};

int main()
{
    Solution sol;
    int count;
    std::vector<int> nums;

    // Example 1
    nums = {3, 1};
    count = sol.countMaxOrSubsets(nums);
    std::cout << "Answser: 2" << std::endl;
    std::cout << "Output: " << count << std::endl;

    // Example 2
    nums = {2, 2, 2};
    count = sol.countMaxOrSubsets(nums);
    std::cout << "Answser: 7" << std::endl;
    std::cout << "Output: " << count << std::endl;

    // Example 3
    nums = {3, 2, 1, 5};
    count = sol.countMaxOrSubsets(nums);
    std::cout << "Answser: 6" << std::endl;
    std::cout << "Output: " << count << std::endl;

    return 0;
}