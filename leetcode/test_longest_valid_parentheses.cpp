#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>
#include "leetcode/longest_valid_parentheses.hpp"


BOOST_AUTO_TEST_SUITE(test_longest_valid_parentheses)
BOOST_AUTO_TEST_CASE(test_0)
{
    leetcode::Solution sol;
    std::string s;

    s = "(()";
	BOOST_TEST_CHECK(sol.longestValidParentheses(s) == 2);

    s = ")()())";
	BOOST_TEST_CHECK(sol.longestValidParentheses(s) == 4);
    
    s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
	BOOST_TEST_CHECK(sol.longestValidParentheses(s) == 132);
}
BOOST_AUTO_TEST_SUITE_END()