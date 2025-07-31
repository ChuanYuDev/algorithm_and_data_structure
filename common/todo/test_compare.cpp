#define BOOST_TEST_MODULE test_compare

#include <boost/test/unit_test.hpp>
#include "common/compare.hpp"

BOOST_AUTO_TEST_SUITE(test_compare)

BOOST_AUTO_TEST_CASE(test_are_vectors_same_0)
{
    std::vector<double> v0 = {1.1, 2.2, 3.0};
    std::vector<double> v1 = {1.1, 2.2, 3.0};
    BOOST_TEST_CHECK(common::areVectorsSame(v0, v1));
}

BOOST_AUTO_TEST_CASE(test_are_vectors_same_1)
{
    std::vector<double> v0 = {1.1, 2.2, 3.0};
    std::vector<double> v1 = {1.1, 2.3, 3.0};
    BOOST_TEST_CHECK(!common::areVectorsSame(v0, v1));
}

BOOST_AUTO_TEST_SUITE_END()