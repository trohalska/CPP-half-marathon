cmake_minimum_required(VERSION 3.18.2)

set(CONTAINERS_SRCS
    Containers/Container.cpp
    Containers/Barrel.cpp
    Containers/Chest.cpp
    Containers/Safe.cpp

)
set(PLAYER_SRCS
    Player/Player.cpp
)
set(SOURCES ${CONTAINERS_SRCS} ${PLAYER_SRCS})

include_directories(. ./Containers ./Player ./Interfaces)

add_library(lib ${SOURCES})

target_include_directories(lib INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)