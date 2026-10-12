cmake_minimum_required(VERSION 3.20)

project(turn_based_rpg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(turn_based_rpg
    turn_based_rpg/src/main.cpp
    turn_based_rpg/src/Player.cpp
    turn_based_rpg/src/Enemy.cpp
    turn_based_rpg/src/Battle.cpp
)

target_include_directories(turn_based_rpg
    PRIVATE
        turn_based_rpg/include
)
