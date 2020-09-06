cmake_minimum_required(VERSION 3.1)

project(draugr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")

option(USE_SRC "use src" ON)
option(USE_UTILS "utils" OFF)

if(USE_SRC)
  add_subdirectory(src)
  list(APPEND EXTRA_LIBS lib)
endif()

if(USE_UTILS)
  list(APPEND EXTRA_LIBS2 utils)
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS} ${EXTRA_LIBS2})
target_include_directories(	${PROJECT_NAME} PUBLIC
							"${PROJECT_BINARY_DIR}"
							)