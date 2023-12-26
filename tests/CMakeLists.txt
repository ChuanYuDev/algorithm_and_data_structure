set(Boost_USE_SATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(TEST_LIB test_lib)
add_library(${TEST_LIB} INTERFACE)
target_include_directories(
    ${TEST_LIB} INTERFACE 
    ${LEETCODE_PUBLIC_HEADER}
    ${LEETCODE_PRIVATE_HEADER}
)

target_link_libraries(${TEST_LIB} INTERFACE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

function(add_leetcode_test TEST_NAME TEST_SRC)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME}  ${TEST_LIB})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

add_leetcode_test(test_1_two_sum test_1_two_sum.cpp)

add_executable(test_56_merge_intervals test_56_merge_intervals.cpp)
target_link_libraries(test_56_merge_intervals PUBLIC ${TEST_LIB})

add_leetcode_test(test_84_largest_rectangle_in_histogram test_84_largest_rectangle_in_histogram.cpp)