cmake_minimum_required(VERSION 3.12)
project(sfml_tutorial)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(sfml_tutorial main.cpp Animation.h Player.h Collider.h Platform.h)

target_link_libraries(sfml_tutorial sfml-graphics sfml-audio)