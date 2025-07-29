#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<std::vector<int>> result;
    int size;

    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        result = {};
        size = nums.size();

        // subsets({1 2 3})
        // subset: the subset before {1 2 3}
        // Empty -> {}
        // 1
        //      subsets({2 3})
        //          Empty -> {1}
        //          2
        //              subsets({3})
        //                  Empty -> {1 2}
        //                  3
        //                      subsets({})
        //                          Empty -> {1 2 3}    
        //          3
        //              subsets({})
        //                  Empty -> {1 3}
        // 2
        //      subsets({3})
        //          Empty -> {2}
        //          3
        //              subsets({})
        //                  Empty -> {2 3}
        // 3
        //      subsets({})
        //      Empty -> {3}
        std::vector<int> subset;
        subsets(nums, 0, subset);

        return result;
    }

    void subsets(std::vector<int> &nums, int start, std::vector<int> &subset) 
    {
        // Based on the first element of the subset
        // Empty
        // Add subset to result (Copy the subset into the result)
        result.push_back(subset);

        for (int i = start; i < size; i++)
        {
            // // Create new subset
            // std::vector<int> subset_copy = subset;

            // // Add nums[i] to the subset
            // subset_copy.push_back(nums[i]);

            // No need to create new subset
            // When subsets() returns, it means we enumerate all the subsets begin with nums[i]
            // Next we need to enumerate all the subsets begin with nums[i + 1]
            // Therefore we pop nums[i] from the subset

            // Add nums[i] to the subset
            subset.push_back(nums[i]);

            subsets(nums, i + 1, subset);

            subset.pop_back();
        }
    }
};

void printResult(std::vector<std::vector<int>> &result)
{
    std::cout << "[";
    for (const auto &element: result)
    {
        std::cout << "[";
        for (int ele: element)
        {
            std::cout << ele << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Solution sol;
    std::vector<std::vector<int>> result;
    std::vector<int> nums;

    // Example 1
    nums = {1, 2, 3};
    result = sol.subsets(nums);
    std::cout << "Answer: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]" << std::endl;
    std::cout << "Output: ";

    printResult(result);

    // Example 2
    nums = {0};
    result = sol.subsets(nums);
    std::cout << "Answer: [[],[0]]" << std::endl;
    std::cout << "Output: ";

    printResult(result);

    return 0;
}
