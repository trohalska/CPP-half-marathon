cmake_minimum_required(VERSION 3.18.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic")

project(main LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)
