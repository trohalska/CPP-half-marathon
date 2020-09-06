
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

project(main LANGUAGES CXX)

add_executable(${PROJECT_NAME} main1.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC utils)
target_include_directories(	${PROJECT_NAME} PUBLIC
							"${PROJECT_BINARY_DIR}"
							)