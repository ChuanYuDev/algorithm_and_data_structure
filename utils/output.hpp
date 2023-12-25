#ifndef LEETCODE_OUTPUT_HPP_
#define LEETCODE_OUTPUT_HPP_

#include <vector>
#include <iostream>

namespace leetcode
{

template <typename T>
std::ostream & operator<<(std::ostream &os, std::vector<std::vector<T>> v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v[i].size(); ++j){
            os << v[i][j] << ' ';
        }

        os << '\n';
    }

    return os;
}

} // namespace leetcode 

#endif // LEETCODE_OUTPUT_HPP_