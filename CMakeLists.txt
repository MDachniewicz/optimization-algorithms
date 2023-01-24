cmake_minimum_required(VERSION 3.10)
project(MyProject CXX)

add_library(OptimizationAlgorithms OptimizationAlgorithms.cpp OptimizationAlgorithms.h)

add_executable(BDS BDS.cpp)
target_link_libraries(BDS OptimizationAlgorithms)

add_executable(lagrange lagrange.cpp)
target_link_libraries(lagrange OptimizationAlgorithms)