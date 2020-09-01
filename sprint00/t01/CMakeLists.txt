cmake_minimum_required(VERSION 3.16.3)
project(printDialog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic")

set(SOURCE printDialog.cpp)
set(HEADER printDialog.h)

add_executable(${PROJECT_NAME} ${SOURCE})

set(FOLDER "./../")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME} ${FOLDER})
