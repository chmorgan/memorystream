cmake_minimum_required(VERSION 3.10.2)

project(MemoryStream)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(FindValgrind)
if(VALGRIND_FOUND)
    message(STATUS "Appending ${VALGRIND_INCLUDE_DIR} for Valgrind headers")
    include_directories(${VALGRIND_INCLUDE_DIR})
    list(APPEND EXTERNAL_INCLUDE_DIRS ${VALGRIND_INCLUDE_DIR})
endif()

# use c++11
set(CMAKE_CXX_STANDARD 11)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(./)
add_executable(mstest test/test.cpp memorystream.c)

add_test(mstest mstest)

if(VALGRIND_FOUND)
    add_test(mstest_valgrind valgrind --error-exitcode=1 --leak-check=full ./mstest)
endif()
