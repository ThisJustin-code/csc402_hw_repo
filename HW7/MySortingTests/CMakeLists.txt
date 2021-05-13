cmake_minimum_required(VERSION 3.17)
project(MySortingTests)

set(CMAKE_CXX_STANDARD 14)

add_executable(MySortingTests MySortingTests.cpp MyBubbleSort.h MyInsertionSort.h)