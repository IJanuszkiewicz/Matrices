cmake_minimum_required(VERSION 3.27)
project(Matrices)

set(CMAKE_CXX_STANDARD 23)

add_executable(Matrices main.cpp
        Matrix.cpp
        Matrix.h)
