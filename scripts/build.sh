#!/bin/sh

g++ -I./include/ -Wall -std=c++14 ./src/main.cpp ./src/fxx/*/*.cpp -lsfml-graphics -lsfml-system -lsfml-window -o ./megaDan.out
