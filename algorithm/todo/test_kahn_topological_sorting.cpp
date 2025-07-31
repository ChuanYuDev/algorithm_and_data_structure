#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "dsaa/kahn_topological_sorting.hpp"

BOOST_AUTO_TEST_SUITE(test_kahn_topological_sorting)
BOOST_AUTO_TEST_CASE(test_0)
{
	std::vector<int> sort;
    std::vector<std::vector<int>> adjs = {
        {2},
        {0},
        {1},
        {1, 2}
    };

    BOOST_TEST_CHECK(!dsaa::kahnTopologicalSorting(adjs, sort));
}
BOOST_AUTO_TEST_SUITE_END()