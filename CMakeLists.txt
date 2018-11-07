cmake_minimum_required(VERSION 3.9)
project(cppblog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(/usr/local/include)
include_directories(/usr/include/mysql)

add_executable(cppblog index.tmpl.cpp file_server.cpp main.cpp)
target_link_libraries(cppblog cppcms booster)
target_link_libraries(cppblog soci_core soci_mysql)
target_link_libraries(cppblog boost_thread boost_system boost_program_options)
