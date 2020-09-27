cmake_minimum_required(VERSION 3.1)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

project(testvec)

add_executable(test_vec test_vec.cpp)

