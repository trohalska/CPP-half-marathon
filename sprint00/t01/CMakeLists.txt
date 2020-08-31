cmake_minimum_required(VERSION 3.18.1)
project(printDialog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic")

set(SOURCE printDialog.cpp)
set(HEADER printDialog.h)

add_executable(${PROJECT_NAME} ${SOURCE})