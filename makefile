CC			 = g++
CFLAGS		 = -std=c++14 -Wall
EXE			 = ./bin/megaDan.out
LINKSFML	 = -lsfml-graphics -lsfml-system -lsfml-window
DEEPSRC		 = ./src/fxx/
DEPENDENCIES = ./src/obj/main.o $(DEEPSRC)*/obj/*.o 

$(EXE) : $(DEPENDENCIES)
	$(CC) $(CFLAGS) $(DEPENDENCIES) $(LINKSMFL) -o $(EXE)

