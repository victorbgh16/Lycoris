cmake_minimum_required(VERSION 3.23)
project(Lycoris)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lycoris src/lexer.cpp includes/lexer.hpp)
