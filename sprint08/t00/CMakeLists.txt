cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")
set(CMAKE_CXX_EXTENSIONS OFF)

project(smartPointers LANGUAGES CXX)

include_directories(app/src)

add_subdirectory(app)
