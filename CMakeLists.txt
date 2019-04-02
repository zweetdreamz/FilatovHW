cmake_minimum_required(VERSION 3.12)
project(FilatovHW)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(FilatovHW main.cpp Graph.hpp)