CC			 = g++
CFLAGS		 = -std=c++14 -Wall
EXE			 = ./bin/megaDan.out
LINKSFML	 = -lsfml-graphics -lsfml-system -lsfml-window
DEEPSRC		 = ./src/fxx/
DEPENDENCIES = ./src/obj/main.o $(SRCACTORS)obj/actor.o $(SRCACTORS)obj/brick.o $(SRCACTORS)obj/collidable.o $(SRCACTORS)obj/drawable.o $(SRCACTORS)obj/mobile.o $(SRCACTORS)obj/player.o ./src/fxx/directors/obj/game.o ./src/fxx/hands/obj/animation.o ./src/fxx/props/obj/tile.o
INCLUDE		 = ./include
SRCACTORS    = ./src/fxx/actors/
SRCDIRECTORS = ./src/fxx/directors/
SRCHANDS     = ./src/fxx/hands/
SRCPROPS     = ./src/fxx/props/

.PHONY : clean all run

$(EXE) : $(DEPENDENCIES)
#	$(CC) $(CFLAGS) $(DEPENDENCIES) -o $(EXE) $(LINKSMFL) # OMFG, TYPO like Mr. Bentley. SFML, not SMFL LOL
	@$(CC) $(CFLAGS) $(DEPENDENCIES) -o $(EXE) $(LINKSFML)
	@echo './bin/megaDan.out' is built!

./src/obj/main.o : ./src/main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c ./src/main.cpp -o ./src/obj/main.o

$(SRCACTORS)obj/actor.o : $(SRCACTORS)actor.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)actor.cpp -o $(SRCACTORS)obj/actor.o

$(SRCACTORS)obj/brick.o : $(SRCACTORS)brick.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)brick.cpp -o $(SRCACTORS)obj/brick.o

$(SRCACTORS)obj/collidable.o : $(SRCACTORS)collidable.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)collidable.cpp -o $(SRCACTORS)obj/collidable.o

$(SRCACTORS)obj/drawable.o : $(SRCACTORS)drawable.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)drawable.cpp -o $(SRCACTORS)obj/drawable.o

$(SRCACTORS)obj/mobile.o : $(SRCACTORS)mobile.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)mobile.cpp -o $(SRCACTORS)obj/mobile.o

$(SRCACTORS)obj/player.o : $(SRCACTORS)player.cpp $(INCLUDE)/fxx/actors/player.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCACTORS)player.cpp -o $(SRCACTORS)obj/player.o

$(SRCDIRECTORS)obj/game.o : $(SRCDIRECTORS)game.cpp $(INCLUDE)/fxx/directors/game.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCDIRECTORS)game.cpp -o $(SRCDIRECTORS)obj/game.o

$(SRCHANDS)obj/animation.o : $(SRCHANDS)animation.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCHANDS)animation.cpp -o $(SRCHANDS)obj/animation.o

$(SRCPROPS)obj/tile.o : $(SRCPROPS)tile.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCPROPS)tile.cpp -o $(SRCPROPS)obj/tile.o

clean :
	@rm -f ./src/obj/main.o
	@rm -f $(DEEPSRC)*/obj/*.o
	@rm -f ./bin/megaDan.out

all : clean $(EXE)

run : $(EXE)
	@./bin/megaDan.out #run the program
