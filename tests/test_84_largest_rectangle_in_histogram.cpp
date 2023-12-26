#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/84_largest_rectangle_in_histogram.hpp"

struct Fixture
{
    Fixture() {}
    ~Fixture() {}
    leetcode::Solution sol;
    std::vector<int> heights;
};

BOOST_FIXTURE_TEST_SUITE(test_84, Fixture)
BOOST_AUTO_TEST_CASE(test_0)
{
    heights = {2, 1, 5, 6, 2, 3};
    BOOST_TEST_CHECK(sol.largestRectangleArea(heights) == 10);

    heights = {2, 4};
    BOOST_TEST_CHECK(sol.largestRectangleArea(heights) == 4);

}
BOOST_AUTO_TEST_SUITE_END()