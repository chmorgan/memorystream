cmake_minimum_required(VERSION 3.10.2)

project(MemoryStream)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(FindValgrind)
if(DEFINED VALGRIND_PROGRAM)
    message(STATUS "Found valgrind program")
endif()

# use c++11
set(CMAKE_CXX_STANDARD 11)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(./)
add_executable(mstest test/test.cpp memorystream.c)

add_test(mstest mstest)

if(DEFINED VALGRIND_PROGRAM)
    add_test(mstest_valgrind valgrind --error-exitcode=1 --leak-check=full ./mstest)
endif()
