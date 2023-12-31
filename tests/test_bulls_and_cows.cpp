#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/bulls_and_cows.hpp"

BOOST_AUTO_TEST_SUITE(test_bulls_and_cows)
BOOST_AUTO_TEST_CASE(test_0)
{
    leetcode::Solution sol;
    std::string secret, guess;

    secret = "1807", guess = "7810";
    BOOST_TEST_CHECK(sol.getHint(secret, guess) == "1A3B");

    secret = "1123", guess = "0111";
    BOOST_TEST_CHECK(sol.getHint(secret, guess) == "1A1B");

}
BOOST_AUTO_TEST_SUITE_END()