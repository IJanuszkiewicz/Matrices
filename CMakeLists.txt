cmake_minimum_required(VERSION 3.25)
project(Matrices)

set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

include(CTest)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_library(Matrices src/Matrix.cpp)

add_executable(matrixTest test/matrixTest.cpp)

target_link_libraries(matrixTest PRIVATE Matrices gtest_main)

gtest_discover_tests(matrixTest)
