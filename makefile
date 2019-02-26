CC			 = g++
CFLAGS		 = -std=c++14 -Wall
EXE			 = ./bin/megaDan.out
LINKSFML	 = -lsfml-graphics -lsfml-system -lsfml-window
DEEPSRC		 = ./src/fxx/
DEPENDENCIES = ./src/obj/main.o $(DEEPSRC)*/obj/*.o 
INCLUDE		 = ./include



.PHONY : clean

$(EXE) : $(DEPENDENCIES)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(DEPENDENCIES) $(LINKSMFL) -o$(EXE)

./src/obj/main.o : ./src/main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/main.cpp -o ./src/obj/main.o

./src/fxx/actors/obj/actor.o : ./src/fxx/actors/actor.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/actors/actor.cpp -o ./src/fxx/actors/obj/actor.o

./src/fxx/actors/obj/brick.o : ./src/fxx/actors/brick.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/actors/brick.cpp -o ./src/fxx/actors/obj/brick.o

./src/fxx/actors/obj/collidable.o : ./src/fxx/actors/collidable.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/actors/collidable.cpp -o ./src/fxx/actors/obj/collidable.o

./src/fxx/actors/obj/drawable.o : ./src/fxx/actors/drawable.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/actors/drawable.cpp -o ./src/fxx/actors/obj/drawable.o

./src/fxx/actors/obj/mobile.o : ./src/fxx/actors/mobile.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/actors/mobile.cpp -o ./src/fxx/actors/obj/mobile.o

./src/fxx/directors/obj/game.o : ./src/fxx/directors/game.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/directors/game.cpp -o ./src/fxx/directors/obj/game.o

./src/fxx/hands/obj/animation.o : ./src/fxx/hands/animation.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/hands/animation.cpp -o ./src/fxx/hands/obj/animation.o

./src/fxx/props/obj/tile.o : ./src/fxx/props/tile.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/fxx/props/tile.cpp -o ./src/fxx/props/obj/tile.o

clean :
	@rm -f ./src/obj/main.o
	@rm -f $(DEEPSRC)*/obj/*.o

