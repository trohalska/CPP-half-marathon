cmake_minimum_required(VERSION 3.18.2)

file(GLOB CPPS "*.cpp")
add_library(spells ${CPPS})
target_include_directories(spells INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)