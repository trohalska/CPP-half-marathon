cmake_minimum_required(VERSION 3.18.2)

project(lib LANGUAGES CXX)
add_library(lib INTERFACE)
target_include_directories(lib INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)