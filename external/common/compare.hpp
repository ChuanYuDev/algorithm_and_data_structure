#ifndef COMMON_COMPARE_HPP_
#define COMMON_COMPARE_HPP_

#include <vector>

namespace common
{

template <typename T>
bool areVectorsSame(const std::vector<T> &v0, const std::vector<T> &v1)
{
    if (v0.size() != v1.size())
        return false;
    
    for (std::size_t i = 0; i < v0.size(); ++i)
    {
        if (v0.at(i) != v1.at(i))
            return false;
    }
    return true;
}

} // namespace common

#endif // COMMON_COMPARE_HPP_