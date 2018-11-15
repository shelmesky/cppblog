cmake_minimum_required(VERSION 3.9)
project(cppblog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(/usr/local/include)
include_directories(/usr/include/mysql)
include_directories(./include)

add_executable(cppblog index.tmpl.cpp article.tmpl.cpp archives.tmpl.cpp file_server.cpp archives.cpp main.cpp)
target_link_libraries(cppblog /usr/local/lib/libmarkdown.a)
target_link_libraries(cppblog cppcms booster)
target_link_libraries(cppblog soci_core soci_mysql)
target_link_libraries(cppblog boost_thread boost_system)
