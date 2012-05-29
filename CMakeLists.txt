# CMake build script for CompilerKit
# Building:
# > mkdir build && cd build
# > cmake ..
# > cmake --build .
#
# CMake Tutorial: http://www.cmake.org/cmake/help/cmake_tutorial.html
# CMake Example:  https://github.com/libgit2/libgit2/blob/development/CMakeLists.txt

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(CompilerKit C)

# INCLUDE_DIRECTORIES(src include)

# Compile and link CompilerKit
# ADD_LIBRARY(CompilerKit ${SRC})

ADD_EXECUTABLE(compilerkit-demo examples/demo.c)
# TARGET_LINK_LIBRARIES(compilerkit-demo CompilerKit)
