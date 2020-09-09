cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

project(magicSpells LANGUAGES CXX)

include_directories(app/src/Creatures app/src/Spells)

add_subdirectory(app)