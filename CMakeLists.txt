cmake_minimum_required(VERSION 3.27)
project(Heap)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heap main.cpp
        HeapException.h
        HeapException.cpp
        HeapOfInt.cpp
        HeapOfInt.h)
