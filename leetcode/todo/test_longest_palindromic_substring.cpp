#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/longest_palindromic_substring.hpp"

BOOST_AUTO_TEST_SUITE(test_longest_palindromic_substring)
BOOST_AUTO_TEST_CASE(test_0)
{
	leetcode::Solution sol;
	std::string s;

	s = "babad";
	BOOST_TEST_CHECK(sol.longestPalindrome(s) == "bab");

	s = "cbbd";
	BOOST_TEST_CHECK(sol.longestPalindrome(s) == "bb");

	s = "lmabcbac";
	BOOST_TEST_CHECK(sol.longestPalindrome(s) == "abcba");

	s = "";
	BOOST_TEST_CHECK(sol.longestPalindrome(s) == "");
}
BOOST_AUTO_TEST_SUITE_END()