#include <vector>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // Create unordered map
        //      nums[i], i
        std::unordered_map<int, int> map;
        std::vector<int> result;
        int temp;

        // Traverse nums
        int length = nums.size();

        for (int i = 0; i < length; ++i)
        {
            // Calculate
            //      int temp = target - nums[i]
            temp = target - nums[i];

            std::unordered_map<int, int>::iterator map_ptr = map.find(temp);

            // If temp is in the map
            //      temp and nums[i] are results
            if (map_ptr != map.end())
            {
                result.push_back(map_ptr->second);
                result.push_back(i);
                break;
            }
            // If temp is not in the map
            //      Save nums[i] to the map
            else
            {
                map.insert(std::make_pair(nums[i], i));
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
	std::vector<int> nums;
    std::vector<int> result;
    int target;
    
    // Example 1
    nums = {2, 7, 11, 15};
	target = 9;
	result= solution.twoSum(nums, target);

    std::cout << "Answer: 0 1" << std::endl;
    std::cout << "Output: " << result[0] << " " << result[1] << std::endl;

    // Example 2
    nums = {3, 2, 4};
	target = 6;
	result= solution.twoSum(nums, target);

    std::cout << "Answer: 1 2" << std::endl;
    std::cout << "Output: " << result[0] << " " << result[1] << std::endl;

    // Example 3
    nums = {3, 3};
	target = 6;
	result= solution.twoSum(nums, target);

    std::cout << "Answer: 0 1" << std::endl;
    std::cout << "Output: " << result[0] << " " << result[1] << std::endl;
    return 0;
}