cmake_minimum_required(VERSION 3.20)
project(Optimization)

set(CMAKE_CXX_STANDARD 20)

add_executable(Optimization main.cpp Vector.cpp Vector.h Algorithms.h Functions.h Matrix.cpp Matrix.h LinAlg.h)
