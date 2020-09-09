cmake_minimum_required(VERSION 3.18.2)

set(FOOD_SRCS
    Food/ApplePie.cpp
    Food/HoneyNut.cpp
    Food/PoisonedFood.cpp
    Food/SweetRoll.cpp
)
set(WIZARD_SRCS
    Wizard/MightyWizard.cpp
)
set(SOURCES ${FOOD_SRCS} ${WIZARD_SRCS})

include_directories(. ./Containers ./Player ./Interfaces)

add_library(lib ${SOURCES})

target_include_directories(lib INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)