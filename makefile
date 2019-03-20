CC		 = g++
CFLAGS	 = -std=c++14 -Wall -Wextra -pedantic
INCLUDE	 = ./include/
LINK	 = $(CC) $(CFLAGS)
COMPILE	 = $(CC) $(CFLAGS) -I$(INCLUDE) -c # Included this macro to shorted some lines
BUILD	 = $(CC) $(CFLAGS) -I$(INCLUDE) # Included this macro to shorted some lines
EXE		 = ./bin/megaDan.out
LINKSFML = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
DSRC	 = ./src/fxx/

LIBSRC   = ./libsrc/
LIBDIR   = ./lib/
LFLAGS   = -shared -fPIC # fPIC is Position-Independent Code
SHRLIB   = $(LIBDIR)libactors.so
LINKSHR  = -L$(LIBDIR) -lactors

ACTINC	 = $(INCLUDE)fxx/actors/
DRCINC   = $(INCLUDE)fxx/directors/
HNDINC   = $(INCLUDE)fxx/hands/
PRPINC   = $(INCLUDE)fxx/props/

ACTSRC   = $(LIBSRC)actors/
DRCSRC	 = $(DSRC)directors/
HNDSRC   = $(DSRC)hands/
PRPSRC   = $(DSRC)props/

DRCOBJ	 = $(DSRC)directors/obj/
ACTOBJ	 = $(LIBSRC)actors/obj/
HNDOBJ	 = $(DSRC)hands/obj/
PRPOBJ	 = $(DSRC)props/obj/
SRCOBJ   = ./src/obj/

EXEDEPS	 = $(SRCOBJ)main.o $(DRCOBJ)game.o $(DRCOBJ)menu.o $(HNDOBJ)animation.o $(PRPOBJ)tile.o

LIBDEPS	 = $(ACTOBJ)actor.o $(ACTOBJ)brick.o $(ACTOBJ)collidable.o $(ACTOBJ)drawable.o $(ACTOBJ)mobile.o $(ACTOBJ)player.o

.PHONY : clean all run

# Rule to create the primary executable, './bin/megaDan.out'
$(EXE) : $(EXEDEPS) $(SHRLIB) 
	@$(LINK) $(LINKSFML) $(LINKSHR) $(EXEDEPS) -o $(EXE)
	@echo './bin/megaDan.out' is built!

# Rule to create the shared library, 'libactors.so'
$(SHRLIB) : $(LIBDEPS)
	@$(BUILD) $(LFLAGS) $(ACTOBJ)*.o -o $(SHRLIB)

$(SRCOBJ)main.o : ./src/main.cpp
	$(COMPILE) ./src/main.cpp -o $(SRCOBJ)main.o

$(DRCOBJ)menu.o : $(DRCSRC)Menu.cpp $(DRCINC)Menu.h
	$(COMPILE) $(DRCSRC)Menu.cpp -o $(DRCOBJ)menu.o

$(ACTOBJ)actor.o : $(ACTSRC)actor.cpp $(ACTINC)actor.h
	$(COMPILE) $(ACTSRC)actor.cpp -o $(ACTOBJ)actor.o

$(ACTOBJ)brick.o : $(ACTSRC)brick.cpp $(ACTINC)brick.h
	$(COMPILE) $(ACTSRC)brick.cpp -o $(ACTOBJ)brick.o

$(ACTOBJ)collidable.o : $(ACTSRC)collidable.cpp $(ACTINC)collidable.h
	$(COMPILE) $(ACTSRC)collidable.cpp -o $(ACTOBJ)collidable.o

$(ACTOBJ)drawable.o : $(ACTSRC)drawable.cpp $(ACTINC)drawable.h
	$(COMPILE) $(ACTSRC)drawable.cpp -o $(ACTOBJ)drawable.o

$(ACTSRC)obj/mobile.o : $(ACTSRC)mobile.cpp $(ACTINC)mobile.h
	$(COMPILE) $(ACTSRC)mobile.cpp -o $(ACTOBJ)mobile.o

$(ACTOBJ)player.o : $(ACTSRC)player.cpp $(ACTINC)player.h
	$(COMPILE) $(ACTSRC)player.cpp -o $(ACTOBJ)player.o

$(DRCOBJ)game.o : $(DRCSRC)game.cpp $(DRCINC)game.h
	$(COMPILE) $(DRCSRC)game.cpp -o $(DRCOBJ)game.o

$(HNDOBJ)animation.o : $(HNDSRC)animation.cpp $(HNDINC)animation.h
	$(COMPILE) $(HNDSRC)animation.cpp -o $(HNDOBJ)animation.o

$(PRPOBJ)tile.o : $(PRPSRC)tile.cpp $(PRPINC)tile.h
	$(COMPILE) $(PRPSRC)tile.cpp -o $(PRPOBJ)tile.o

clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(DSRC)*/obj/*.o
	@rm -f $(ACTOBJ)*.o
	@rm -f $(EXE)

all : clean $(EXE)

run : $(EXE)
	@$(EXE) #run the program
