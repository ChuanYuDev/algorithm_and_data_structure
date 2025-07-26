/* Description:
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.

 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return[0, 1].
*/

# include <vector>
# include <unordered_map>
# include <iostream>

std::vector<int> twoSum(std::vector<int> &nums, int target){
    std::unordered_map<int, int> um;
    std::unordered_map<int, int>::iterator iter;
    int num;
    std::vector<int> ans;

    for (int i = 0; i < nums.size(); ++i){
        num = nums[i];
        iter = um.find(target - num);
        if (iter != um.end()){
            ans.push_back(i);
            ans.push_back(iter->second);
            break;
        }
        else{
            um.insert(std::make_pair(num, i));
        }
    }    
    return ans;
}

int main(){
    std::vector<int> nums = {3,2,4};
    int target = 6;

    std::vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << std::endl;

    return 0;
}