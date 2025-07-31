#ifndef DSAA_SORT_HPP_
#define DSAA_SORT_HPP_

#include <vector>

namespace dsaa
{

template <typename T>
void selectionSort(std::vector<T> &v)
{
    std::size_t min_id = 0;
    T tmp;

    for(std::size_t i = 0; i < v.size(); ++i)
    {
        min_id = i;

        for(std::size_t j = i + 1; j < v.size(); ++j)
        {
            if (v.at(j) < v.at(min_id))
                min_id = j;
        }

        if (min_id != i)
            std::swap(v.at(i), v.at(min_id));
    }
}

template <typename T>
void insertionSort(std::vector<T> &v)
{
    T key;
    std::size_t j;

    for (std::size_t i = 1; i < v.size(); ++i)
    {
        key = v.at(i);

        j = 1;

        for (; j <= i; ++j)
        {
            if (v.at(i - j) > key)
                v.at(i - j + 1) = v.at(i - j);
            else
                break;
        }

        v.at(i - j + 1) = key;
    }
}

template <typename T>
void bubbleSort(std::vector<T> &v)
{
    T tmp;
    bool swap;

    std::size_t num = v.size();

    for (std::size_t i = 0; i < num; ++i)
    {
        swap = false;

        for (std::size_t j = 0; j < num - 1 - i; ++j)
        {
            if (v.at(j) > v.at(j + 1))
            {
                std::swap(v.at(j), v.at(j + 1));
                swap = true;
            }
        }

        if (!swap)
            break;
    }
}

template <typename T>
std::vector<T> mergeSort(std::vector<T> &v, std::size_t begin, std::size_t end)
{
    if (end - begin == 0)
        return {};

    if (end - begin == 1)
        return {v.at(begin)};

    std::size_t mid = (begin + end) / 2; 

    auto left = mergeSort(v, begin, mid);
    auto right = mergeSort(v, mid, end);

    std::size_t i = 0, j = 0;

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
        }
    }
    
    return result;
}

template <typename T>
std::vector<T> mergeSort(std::vector<T> &v)
{
    return mergeSort(v, 0, v.size());    
}

} // namespace dsaa

#endif // DSAA_SORT_HPP_