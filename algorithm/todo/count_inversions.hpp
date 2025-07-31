#ifndef DSAA_COUNT_INVERSIONS_HPP_
#define DSAA_COUNT_INVERSIONS_HPP_

#include <vector>
#include <cstdint>

namespace dsaa
{

template <typename T>
std::pair<std::vector<T>, std::uint32_t> countInversions(std::vector<T> &v, std::size_t begin, std::size_t end)
{
    if (end - begin == 0)
        return {{}, 0};

    if (end - begin == 1)
        return {{v[begin]}, 0};

    std::size_t mid = (begin + end) / 2;

    const auto pair_left = countInversions(v, begin, mid);
    const auto &left = pair_left.first;

    const auto pair_right = countInversions(v, mid, end);
    const auto &right = pair_right.first;

    std::size_t i = 0, j = 0, split_inversions_num = 0;

    std::vector<T> result;

    for (std::size_t k = 0; k < end - begin; ++k)
    {
        if (i >= mid - begin)
        {
            result.push_back(right.at(j));
            ++j;
            continue;
        }

        if (j >= end - mid)
        {
            result.push_back(left.at(i));
            ++i;
            continue;
        }

        if (left.at(i) < right.at(j))
        {
            result.push_back(left.at(i));
            ++i;
        }
        else
        {
            result.push_back(right.at(j));
            ++j;
            split_inversions_num += mid - i - begin;
        }
    }

    return {result, pair_left.second + split_inversions_num + pair_right.second};
}

template <typename T>
std::pair<std::vector<T>, uint32_t> countInversions(std::vector<T> &v)
{
    return countInversions(v, 0, v.size());
}

} // namespace dsaa

#endif // DSAA_COUNT_INVERSIONS_HPP_