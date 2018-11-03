cmake_minimum_required(VERSION 3.9)
project(cppblog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(cppblog main.cpp)
target_link_libraries(cppblog cppcms)
