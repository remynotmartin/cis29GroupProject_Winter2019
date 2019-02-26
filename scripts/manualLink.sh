#!/bin/sh

FXX="./src/fxx"

g++ -Wall -std=c++14 ./src/obj/main.o $FXX/*/obj/*.o -o ./bin/megaDan.out -lsfml-window -lsfml-graphics -lsfml-system 
