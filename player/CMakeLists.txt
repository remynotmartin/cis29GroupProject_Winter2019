cmake_minimum_required(VERSION 3.12)
project(player)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(player main.cpp Animation.h player.h)

target_link_libraries(player sfml-graphics sfml-audio)
