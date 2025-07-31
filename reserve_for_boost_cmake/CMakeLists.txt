cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(leetcode VERSION 0.1.2)

set(LEETCODE_PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/)
set(LEETCODE_PRIVATE_HEADER ${CMAKE_SOURCE_DIR}/)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(tests)