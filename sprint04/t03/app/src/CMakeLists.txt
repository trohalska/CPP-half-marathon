cmake_minimum_required(VERSION 3.1)

file(GLOB CPPS "*.cpp")
add_library(lib ${CPPS})
