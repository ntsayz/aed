cmake_minimum_required(VERSION 3.10)
project(aed2122_ci1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aed2122_ci1 main.cpp Tests/tests.cpp Tests/Bookstore.cpp Tests/Book.cpp Tests/Warehouse.cpp Tests/Packer.cpp Tests/Order.cpp)

target_link_libraries(aed2122_ci1 gtest gtest_main)
