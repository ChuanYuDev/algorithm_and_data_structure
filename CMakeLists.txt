cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(leetcode)

set(LEETCODE_PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/)
set(LEETCODE_PRIVATE_HEADER ${CMAKE_SOURCE_DIR}/)

add_subdirectory(tests)