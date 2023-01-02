# AED 2021/2022 - CI2 - Parte Prática
# Pedro Ribeiro (DCC/FCUP) [12/02/2022]

cmake_minimum_required(VERSION 3.10)
project(aed2122_ci2_pratica)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2122_ci2_pratica main.cpp Tests/tests.cpp Tests/funWithGraphs.cpp Tests/graph.cpp Tests/minHeap.h)

target_link_libraries(aed2122_ci2_pratica gtest gtest_main)
