cmake_minimum_required(VERSION 3.12)
project(cis29GroupProject_Winter2019)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/fxx)
include_directories(include/fxx/actors)
include_directories(include/fxx/directors)
include_directories(include/fxx/hands)
include_directories(include/fxx/props)

add_executable(cis29GroupProject_Winter2019
    include/fxx/actors/actor.h
    include/fxx/actors/brick.h
    include/fxx/actors/collidable.h
    include/fxx/actors/drawable.h
    include/fxx/actors/mobile.h
    include/fxx/actors/player.h
    include/fxx/directors/game.h
    include/fxx/hands/animation.h
    include/fxx/props/tile.h
    src/fxx/actors/actor.cpp
    src/fxx/actors/brick.cpp
    src/fxx/actors/collidable.cpp
    src/fxx/actors/drawable.cpp
    src/fxx/actors/mobile.cpp
    src/fxx/actors/player.cpp
    src/fxx/directors/game.cpp
    src/fxx/hands/animation.cpp
    src/fxx/props/tile.cpp
    src/main.cpp)
