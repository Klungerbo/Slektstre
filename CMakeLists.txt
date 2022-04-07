cmake_minimum_required(VERSION 3.21)
project(Slektstre)

set(CMAKE_CXX_STANDARD 14)
include(CTest)
add_test(test add_test)
add_executable(Slektstre
        main.cpp
        myTree.h
        myTree.cpp
        README.md)

