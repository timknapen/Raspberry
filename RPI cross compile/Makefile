#
#	Makefile for compiling c++ with wiringPi for Raspberry Pi on OSX 10.9 Mavericks
#	https://projects.drogon.net/wiring-pi
#	http://www.jaredwolff.com/blog/cross-compiling-on-mac-osx-for-raspberry-pi/
#
#	This makefile compiles all cpp files in the current folder
#	and creates the executable "App" file in ./bin/
#
#	Compile by typing "make" or "make all"
#	Clean up everything by typing "make clean"
#
#	On the RaspberryPi:
#	start the app by going to the containing folder in terminal and type "sudo App"
#	Exit a running app by typing "Ctrl+c"
#	Stop an app by going to its folder in terminal and typing "sudo killall App"
#	(if "App" is the name of your executable)
#
#	Created by tim knapen on 17/8/14
#	www.timknapen.be
#


#DEBUG	= -g -O0
DEBUG	= -O3

# HOME is the crosstools root folder, on a case sensitive disk image.
# created according to http://www.jaredwolff.com/blog/cross-compiling-on-mac-osx-for-raspberry-pi/
HOME = /Volumes/xtools/arm-none-linux-gnueabi/

# the C compiler on crosstools
CC      = $(HOME)bin/arm-none-linux-gnueabi-gcc

# the C++ compiler on crosstools
CXX     = $(HOME)bin/arm-none-linux-gnueabi-g++

# copy these WiringPi .h files from your raspberry /usr/local/include/ to $(HOME)usr/local/include
# wiringPi.h, wiringPiI2C.h, wiringPiSPI.h, wiringSerial.h, wiringShift.h
INCLUDE	= -I$(HOME)usr/local/include

# flags for the compiler : -pipe should make it use the filesystem less
CPPFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

# copy these WiringPi libraries from your raspberry /usr/local/lib/ to $(HOME)usr/local/lib
# libwiringPi.so libwiringPi.so.2.0 libwiringPiDev.so libwiringPiDev.so.2.0
LDFLAGS	= -L$(HOME)usr/local/lib
LDLIBS  = -lwiringPi -lwiringPiDev -lpthread -lm

# find all the source files
SRC	= $(wildcard *.cpp)
OBJ =  $(addprefix ./bin/,$(SRC:.cpp=.o))

# Create the app on your local disk
PROGRAM = ./bin/App

# Build the app on OSX straight into the Raspberry Pi over your LAN!
# this assumes that your Raspberry Pi is sharing it's root as a Samba shared folder called "PiShare"
# You should create a folder on the Raspberry under /home/pi/Documents/ called "xtools"
# with the right permissions. (for example "sudo chmod 777 ./xtools" when in /home/pi/Documents/ )
# PROGRAM = /Volumes/PiShare/home/pi/Documents/xtools/


##### ACTIONS #########
all: info folder $(PROGRAM)

# a separate folder for .o files and the resulting app
folder:
	@mkdir -p bin

# some info to debug
info:
	@echo action = $(ACTION)
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

# cleans .o files and app, so that we really compile everything again
clean:
	@echo [Clean]
	rm -f $(OBJ) *~ ._* .DS_Store $(PROGRAM)

# compile : create object files from source files
# .c is the prerequisite ($<) and .o the target ($@)
.c.o:
	$(CC) -c $(CPPFLAGS) $< -o $@

.cpp.o:
	$(CXX) -c $(CPPFLAGS) $< -o $@

# use this rule if you both have a .cpp and a .h file
bin/%.o: %.cpp %.h
	$(CXX) -c $(CPPFLAGS) $< -o $@

# use this rule if you only have a .cpp
bin/%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@
