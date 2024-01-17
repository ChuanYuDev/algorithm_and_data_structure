#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "leetcode/lru_cache.hpp"

BOOST_AUTO_TEST_SUITE(test_lru_cache)
BOOST_AUTO_TEST_CASE(test_0)
{
    leetcode::LRUCache lru_cache(2);

    lru_cache.put(1, 1);
    lru_cache.put(2, 2);

    BOOST_TEST_CHECK(lru_cache.get(1) == 1);

    lru_cache.put(3, 3);

    BOOST_TEST_CHECK(lru_cache.get(2) == -1);

    lru_cache.put(4, 4);

    BOOST_TEST_CHECK(lru_cache.get(1) == -1);
    BOOST_TEST_CHECK(lru_cache.get(3) == 3);
    BOOST_TEST_CHECK(lru_cache.get(4) == 4);
}
BOOST_AUTO_TEST_SUITE_END()