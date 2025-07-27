// Make a program which can calculate all prime numbers under a certain number/
#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    std::vector<int> primeNumber(int num) {
        std::vector<int> result;
        int *a = new int[num + 1];

        for (int i = 0; i <= num; ++i)
        {
            a[i] = 1;
        }

        for (int mul = 2; mul <= sqrt(num); ++mul)
        {
            for (int j = 2; mul * j <= num; ++j)
            {
                a[mul * j] = 0;
            }
        }

        for (int i = 2; i <= num; ++i)
        {
            if (a[i] == 1)
            {
                result.push_back(i);
            }
        }

        delete[] a;
        return result;
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
    int num;
    num = 1000;

    std::vector<int> result = sol.primeNumber(num);
    print(result.begin(), result.end());
    return 0;
}