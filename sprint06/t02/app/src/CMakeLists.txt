cmake_minimum_required(VERSION 3.18.2)

set(CREATURE_SRCS
    Creatures/Creature.cpp
    Creatures/Imperial.cpp
    Creatures/Redguard.cpp
)
set(SPELL_SRCS
    Spells/EquilibriumSpell.cpp
    Spells/FireballSpell.cpp
    Spells/FlamesSpell.cpp
    Spells/FreezeSpell.cpp
    Spells/HealingSpell.cpp
)
set(SOURCES ${CREATURE_SRCS} ${SPELL_SRCS})

include_directories(. ./Spells ./Creatures)

add_library(spells ${SOURCES})

target_include_directories(spells INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)