#define BOOST_TEST_MODULE test_utils

#include <boost/test/unit_test.hpp>

#include "common/output.hpp"

BOOST_AUTO_TEST_SUITE(test_output)

using common::operator<<;

BOOST_AUTO_TEST_CASE(test_vector)
{
    std::vector<double> v = {1.1, 2.0, 3, 0.9};
    std::cout << "vector:\n" << v << std::endl;
}

BOOST_AUTO_TEST_CASE(test_vector_of_vector)
{
    std::vector<std::vector<double>> v = {{1.1, 2.0}, {3}, {0.9}};
    std::cout << "vector of vector:\n" << v << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()