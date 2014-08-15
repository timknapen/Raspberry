#
#	Makefile for compiling c++ with wiringPi
#	( https://projects.drogon.net/wiring-pi )
#
#	This makefile compiles all cpp files in the current folder and creates the executable "App" file in ./bin/
#
#	Compile by typing "make" or "make all"
#	Compile and run by typing "make run"
#	Clean up everything by typing "make clean"
#	Exit a running app by typing "Ctrl+c
#	Stop a running an app in the background by typing "make stop"
#
#	Created by tim knapen 10/8/14
#
######################################################################################################

#DEBUG	= -g -O0
DEBUG	= -O3

#the C compiler
CC      = gcc

#the C++ compiler
CXX     = g++
INCLUDE	= -I/usr/local/include
#flags for the compiler : -pipe should make it use the filesystem less
CPPFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L/usr/local/lib
LDLIBS  = -lwiringPi -lwiringPiDev -lpthread -lm

#find all the source files
SRC	= $(wildcard *.cpp)
OBJ =  $(addprefix ./bin/,$(SRC:.cpp=.o))
PROGRAM = ./bin/App


##### ACTIONS #########
all: folder $(PROGRAM)

run: all
	sudo $(PROGRAM)
	
fun:
	sudo $(PROGRAM)
	
stop:
	sudo killall $(PROGRAM)

#put .o files in a separate folder?
folder: 
	@mkdir -p bin

info: #to debug
	@echo CC = $(CC)
	@echo CXX = $(CXX)
	@echo SRC = $(SRC)
	@echo OBJ = $(OBJ)
	@echo INCLUDE = $(INCLUDE)
	@echo CPPFLAGS = $(CPPFLAGS)
	@echo LDFLAGS = $(LDFLAGS), LDLIBS = $(LDLIBS)

$(PROGRAM): $(OBJ)
	@echo [Link]
	$(CXX) -o $(PROGRAM) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@echo Type 'make run' to execute the program.
	@echo Type 'make stop' to stop the program.

# cleans .o files and app, so that we really compile everything again
clean:
	@echo [Clean]
	rm -f $(OBJ) *~ ._* .DS_Store $(PROGRAM)

#compile : create object files from source files
#.c is the prerequisite ($<) and .o the target ($@)
.c.o:
	$(CC) -c $(CPPFLAGS) $< -o $@

.cpp.o: 
	$(CXX) -c $(CPPFLAGS) $< -o $@

#use this rule if you both .cpp and .h file
bin/%.o: %.cpp %.h
	$(CXX) -c $(CPPFLAGS) $< -o $@
	
#use this rule if you only have .cpp
bin/%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@
