cmake_minimum_required(VERSION 3.1)

file(GLOB CPPS "*.cpp")
add_library(mylib ${CPPS})
