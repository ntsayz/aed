cmake_minimum_required(VERSION 3.24)
project(t2_2018)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_2018
        CSimpleList.h
        CStack.h
        Kart.cpp
        Kart.h
        Test.cpp)
