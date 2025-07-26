// You have an array, data inside includes A54 B6 A3 E74 D67 E74 A54 C18 B6 A54 D21
// Write a logic (in any language) to find ALL duplicate values inside the array.
// Your program should return A54 B6 E74

#include <vector>
#include <iostream>
#include <unordered_set>
#include <iterator>

class Solution {
public:
    std::unordered_set<std::string> duplicate(std::vector<std::string>& array)
    {
        std::unordered_set<std::string> seen;
        std::unordered_set<std::string>::iterator p;
        std::unordered_set<std::string> duplicate;

        int len = array.size();

        for (int i = 0; i < len; ++i)
        {
            p = seen.find(array[i]);

            if (p != seen.end())
                duplicate.insert(array[i]);
            else
                seen.insert(array[i]);

        }

        return duplicate;
    }
};

template<class T>
int print(T first, T last){
    for (; first != last; ++first){
        std::cout << *first << " ";
    }
    std::cout << std::endl;
    return 0;
}

int main(){
    Solution sol;
    std::vector<std::string> array;
    array = {"A54", "B6", "A3", "E74", "D67", "E74", "A54", "C18", "B6", "A54", "D21"};
    std::unordered_set<std::string> result;

    result = sol.duplicate(array);
    print(result.begin(), result.end());
    return 0;
}