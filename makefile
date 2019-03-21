CC		 = g++
CFLAGS	 = -std=c++14 -Wall -Wextra -pedantic
INCLUDE	 = ./include/
COMPILE	 = $(CC) $(CFLAGS) -I$(INCLUDE) -c # Included this macro to shorted some lines
BUILD	 = $(CC) $(CFLAGS) -I$(INCLUDE)    # Included this macro to shorted some lines
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

EXEDEPS	 = $(SRCOBJ)main.o $(DRCOBJ)game.o $(DRCOBJ)menu.o $(HNDOBJ)animation.o $(PRPOBJ)tile.o
LIBDEP   = $(LIBOBJ)actor.o $(LIBOBJ)brick.o $(LIBOBJ)collidable.o $(LIBOBJ)drawable.o $(LIBOBJ)mobile.o $(LIBOBJ)player.o

.PHONY : clean all run

# Rule to create the primary executable, './bin/megaDan.out'
$(EXE) : $(EXEDEPS) $(STTLIB) 
	$(BUILD) $(EXEDEPS) $(LINKSFML) $(LINKSTT) -o $(EXE)
	@echo './bin/megaDan.out' is built!

# Rule to create the static library
$(STTLIB) : $(LIBDEP)
	ar r $(STTLIB) $(LIBDEP)

$(LIBOBJ)actor.o : $(ACTSRC)actor.cpp
	$(COMPILE) $(ACTSRC)actor.cpp -o $(LIBOBJ)actor.o

$(LIBOBJ)brick.o : $(ACTSRC)brick.cpp
	$(COMPILE) $(ACTSRC)brick.cpp -o $(LIBOBJ)brick.o

$(LIBOBJ)collidable.o : $(ACTSRC)collidable.cpp
	$(COMPILE) $(ACTSRC)collidable.cpp -o $(LIBOBJ)collidable.o

$(LIBOBJ)drawable.o : $(ACTSRC)drawable.cpp
	$(COMPILE) $(ACTSRC)drawable.cpp -o $(LIBOBJ)drawable.o

$(LIBOBJ)mobile.o : $(ACTSRC)mobile.cpp
	$(COMPILE) $(ACTSRC)mobile.cpp -o $(LIBOBJ)mobile.o

$(LIBOBJ)player.o : $(ACTSRC)player.cpp
	$(COMPILE) $(ACTSRC)player.cpp -o $(LIBOBJ)player.o

$(SRCOBJ)main.o : ./src/main.cpp
	$(COMPILE) ./src/main.cpp -o $(SRCOBJ)main.o

$(DRCOBJ)menu.o : $(DRCSRC)Menu.cpp $(DRCINC)Menu.h
	$(COMPILE) $(DRCSRC)Menu.cpp -o $(DRCOBJ)menu.o

$(DRCOBJ)game.o : $(DRCSRC)game.cpp $(DRCINC)game.h
	$(COMPILE) $(DRCSRC)game.cpp -o $(DRCOBJ)game.o

$(HNDOBJ)animation.o : $(HNDSRC)animation.cpp $(HNDINC)animation.h
	$(COMPILE) $(HNDSRC)animation.cpp -o $(HNDOBJ)animation.o

$(PRPOBJ)tile.o : $(PRPSRC)tile.cpp $(PRPINC)tile.h
	$(COMPILE) $(PRPSRC)tile.cpp -o $(PRPOBJ)tile.o

clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(DSRC)*/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(EXE)

all : clean $(EXE)

run : $(EXE)
	@$(EXE) #run the program
