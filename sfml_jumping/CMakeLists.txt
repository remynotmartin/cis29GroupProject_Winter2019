cmake_minimum_required(VERSION 3.12)
project(sfml_jumping)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(sfml_jumping main.cpp Platform.h Collider.h Player.h Animation.h)

target_link_libraries(sfml_jumping sfml-graphics sfml-audio)

