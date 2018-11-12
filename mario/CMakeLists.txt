cmake_minimum_required(VERSION 3.10)
project(mario)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(mario main.cpp)