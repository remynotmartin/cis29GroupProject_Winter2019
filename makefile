CC		 = g++
CFLAGS	 = -std=c++14 -Wall -Wextra -pedantic
INCLUDE	 = ./include/
COMPILE	 = $(CC) $(CFLAGS) -I$(INCLUDE) -c
BUILD	 = $(CC) $(CFLAGS) -I$(INCLUDE)
EXE		 = ./bin/megaDan.out
LINKSFML = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
LINKSTT  = -L$(LIBDIR) -lactors
DSRC	 = ./src/fxx/

LIBSRC   = ./libsrc/
LIBDIR   = ./lib/
STTLIB   = $(LIBDIR)libactors.a

ACTINC	 = $(INCLUDE)fxx/actors/
DRCINC   = $(INCLUDE)fxx/directors/
HNDINC   = $(INCLUDE)fxx/hands/
PRPINC   = $(INCLUDE)fxx/props/

ACTSRC   = $(LIBSRC)actors/
DRCSRC	 = $(DSRC)directors/
HNDSRC   = $(DSRC)hands/
PRPSRC   = $(DSRC)props/

LIBOBJ	 = $(ACTSRC)obj/
DRCOBJ	 = $(DSRC)directors/obj/
HNDOBJ	 = $(DSRC)hands/obj/
PRPOBJ	 = $(DSRC)props/obj/
SRCOBJ   = ./src/obj/

EXEDEPS	 = $(SRCOBJ)main.o $(DRCOBJ)Game.o $(DRCOBJ)Menu.o $(HNDOBJ)Randomizer.o $(HNDOBJ)Animation.o $(PRPOBJ)Tile.o
LIBDEP   = $(LIBOBJ)Actor.o $(LIBOBJ)Brick.o $(LIBOBJ)Collidable.o $(LIBOBJ)Drawable.o $(LIBOBJ)Mobile.o $(LIBOBJ)Player.o

.PHONY : clean all run

# Rule to create the primary executable, './bin/megaDan.out'
$(EXE) : $(EXEDEPS) $(STTLIB) 
	$(BUILD) $(EXEDEPS) $(LINKSFML) $(LINKSTT) -o $(EXE)
	@echo './bin/megaDan.out' is built!

# Rule to create the static library
$(STTLIB) : $(LIBDEP)
	ar r $(STTLIB) $(LIBDEP)

$(LIBOBJ)Actor.o : $(ACTSRC)Actor.cpp
	$(COMPILE) $(ACTSRC)Actor.cpp -o $(LIBOBJ)Actor.o

$(LIBOBJ)Brick.o : $(ACTSRC)Brick.cpp
	$(COMPILE) $(ACTSRC)Brick.cpp -o $(LIBOBJ)Brick.o

$(LIBOBJ)Collidable.o : $(ACTSRC)Collidable.cpp
	$(COMPILE) $(ACTSRC)Collidable.cpp -o $(LIBOBJ)Collidable.o

$(LIBOBJ)Drawable.o : $(ACTSRC)Drawable.cpp
	$(COMPILE) $(ACTSRC)Drawable.cpp -o $(LIBOBJ)Drawable.o

$(LIBOBJ)Mobile.o : $(ACTSRC)Mobile.cpp
	$(COMPILE) $(ACTSRC)Mobile.cpp -o $(LIBOBJ)Mobile.o

$(LIBOBJ)Player.o : $(ACTSRC)Player.cpp
	$(COMPILE) $(ACTSRC)Player.cpp -o $(LIBOBJ)Player.o

$(SRCOBJ)main.o : ./src/main.cpp
	$(COMPILE) ./src/main.cpp -o $(SRCOBJ)main.o

$(DRCOBJ)Menu.o : $(DRCSRC)Menu.cpp $(DRCINC)Menu.h
	$(COMPILE) $(DRCSRC)Menu.cpp -o $(DRCOBJ)Menu.o

$(DRCOBJ)Game.o : $(DRCSRC)Game.cpp $(DRCINC)Game.h
	$(COMPILE) $(DRCSRC)Game.cpp -o $(DRCOBJ)Game.o

$(HNDOBJ)Animation.o : $(HNDSRC)Animation.cpp $(HNDINC)Animation.h
	$(COMPILE) $(HNDSRC)Animation.cpp -o $(HNDOBJ)Animation.o

$(HNDOBJ)Randomizer.o : $(HNDSRC)Randomizer.cpp $(HNDINC)Randomizer.h
	$(COMPILE) $(HNDSRC)Randomizer.cpp -o $(HNDOBJ)Randomizer.o

$(PRPOBJ)Tile.o : $(PRPSRC)Tile.cpp $(PRPINC)Tile.h
	$(COMPILE) $(PRPSRC)Tile.cpp -o $(PRPOBJ)Tile.o

clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(DSRC)*/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(EXE)

all : clean $(EXE)

run : $(EXE)
	@$(EXE) #run the program
