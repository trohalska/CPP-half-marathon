cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")
set(CMAKE_CXX_EXTENSIONS OFF)

project(utilslib LANGUAGES CXX)

include_directories(app utils)

add_subdirectory(app)
add_subdirectory(utils)