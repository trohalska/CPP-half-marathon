cmake_minimum_required(VERSION 3.16.3)

project(helloTamriel)

add_executable(${PROJECT_NAME} helloTamriel.cpp)

set(FOLDER "./../")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME} ${FOLDER})
