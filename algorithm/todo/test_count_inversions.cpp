#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "external/common/compare.hpp"
#include "dsaa/count_inversions.hpp"

using common::areVectorsSame;

BOOST_AUTO_TEST_SUITE(test_count_inversions)
BOOST_AUTO_TEST_CASE(test_0)
{
    std::vector<double> v = {2.2, 0.9, 1, 5.1, 3.4};
    std::vector<double> v_sort = {0.9, 1, 2.2, 3.4, 5.1};

    auto pair = dsaa::countInversions(v);
    BOOST_TEST_CHECK(areVectorsSame(pair.first, v_sort));
    BOOST_TEST_CHECK(pair.second == 3);
}

BOOST_AUTO_TEST_CASE(test_sort_1)
{
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::vector<int> v_sort = {1, 2, 3, 4, 5};

    auto pair = dsaa::countInversions(v);
    BOOST_TEST_CHECK(areVectorsSame(pair.first, v_sort));
    BOOST_TEST_CHECK(pair.second == 10);
}

BOOST_AUTO_TEST_CASE(test_sort_2)
{
    std::vector<int> v = {1};
    std::vector<int> v_sort = {1};

    auto pair = dsaa::countInversions(v);
    BOOST_TEST_CHECK(areVectorsSame(pair.first, v_sort));
    BOOST_TEST_CHECK(pair.second == 0);
}

BOOST_AUTO_TEST_CASE(test_sort_3)
{
    std::vector<int> v = {1, 2, 3};
    std::vector<int> v_sort = {1, 2, 3};

    auto pair = dsaa::countInversions(v);
    BOOST_TEST_CHECK(areVectorsSame(pair.first, v_sort));
    BOOST_TEST_CHECK(pair.second == 0);
}
BOOST_AUTO_TEST_SUITE_END()