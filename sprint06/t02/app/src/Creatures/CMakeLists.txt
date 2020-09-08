cmake_minimum_required(VERSION 3.18.2)

file(GLOB CPPS "*.cpp")
add_library(creatures ${CPPS})
target_include_directories(creatures INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)