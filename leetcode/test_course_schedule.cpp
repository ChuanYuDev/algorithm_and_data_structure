#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/course_schedule.hpp"

struct Fixture
{
    Fixture() {}
    ~Fixture() {}
    leetcode::Solution sol;
    std::vector<std::vector<int>> prerequisites;
};

BOOST_FIXTURE_TEST_SUITE(test_course_schedule, Fixture)
BOOST_AUTO_TEST_CASE(test_0)
{
    prerequisites = {{1, 0}};
    BOOST_TEST_CHECK(sol.canFinish(2, prerequisites));

    prerequisites = {{1, 0}, {0, 1}};
    BOOST_TEST_CHECK(!sol.canFinish(2, prerequisites));
}
BOOST_AUTO_TEST_SUITE_END()