cmake_minimum_required(VERSION 3.16.3)

file(GLOB CPPS "*.cpp")
add_library(mylib ${CPPS})