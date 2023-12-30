#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/two_sum.hpp"

BOOST_AUTO_TEST_SUITE(test_two_sum)
BOOST_AUTO_TEST_CASE(test_0)
{
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	leetcode::Solution solution;

	auto result= solution.twoSum(nums, target);

    BOOST_TEST_CHECK(result.at(0) == 0);
    BOOST_TEST_CHECK(result.at(1) == 1);

}
BOOST_AUTO_TEST_SUITE_END()