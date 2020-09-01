cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic")

project(moveAlong LANGUAGES CXX)

add_subdirectory(src/)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC mylib)
target_include_directories(	${PROJECT_NAME} PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/src")

set(FOLDER "./../")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME} ${FOLDER})