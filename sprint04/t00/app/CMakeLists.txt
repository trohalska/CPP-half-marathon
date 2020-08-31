cmake_minimum_required(VERSION 3.18.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")

project(main LANGUAGES CXX)
set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

set(FOLDER "/Users/trohalska/CPP/sprint04/t00")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME} ${FOLDER})

target_link_libraries(utils)
