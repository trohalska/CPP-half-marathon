cmake_minimum_required(VERSION 3.18.1)
project(meadSong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic")

set(SOURCE main.cpp meadSong.cpp)
set(HEADER meadSong.h)

add_executable(${PROJECT_NAME} ${SOURCE})