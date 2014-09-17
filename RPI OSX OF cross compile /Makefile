# OF for Raspberry Pi on OSX cross compile makefile #
# by Tim knapen  http://www.timknapen.be
# More info : https://github.com/timknapen/Raspberry

# HOME is the crosstools root folder, on a case sensitive disk image.
# created according to http://www.jaredwolff.com/blog/cross-compiling-on-mac-osx-for-raspberry-pi/
HOME = /Volumes/xtools/arm-none-linux-gnueabi/
RPI_ROOT = $(HOME)

##### NETWORK OR LOCAL ###########
# Create the app from OSX straight on the RPI!
# this assumes that your Raspberry Pi is sharing it's root as a Samba shared folder called "PiShare"
PROGRAM = /Volumes/PiShareB/home/pi/Documents/test/OfApp
# Create the app on your local disk
# PROGRAM = bin/App

# Where to find OF
OF_ROOT =../../../


#DEBUG	= -g -O0
DEBUG	= -O3
OTHER_CPPFLAGS  =
OTHER_CPPFLAGS += -march=armv6
OTHER_CPPFLAGS += -mfpu=vfp
OTHER_CPPFLAGS += -mfloat-abi=hard
OTHER_CPPFLAGS += -fPIC
OTHER_CPPFLAGS += -ftree-vectorize
OTHER_CPPFLAGS += -Wno-psabi
OTHER_CPPFLAGS += -Winline
OTHER_CPPFLAGS += -pipe
OTHER_CPPFLAGS += -DOF_USING_GTK
OTHER_CPPFLAGS += -DOF_USING_MPG123
OTHER_CPPFLAGS += -DTARGET_RASPBERRY_PI
OTHER_CPPFLAGS += -DSTANDALONE
OTHER_CPPFLAGS += -DPIC
OTHER_CPPFLAGS += -D_REENTRANT
OTHER_CPPFLAGS += -D_LARGEFILE64_SOURCE
OTHER_CPPFLAGS += -D_FILE_OFFSET_BITS=64
OTHER_CPPFLAGS += -D_FORTIFY_SOURCE
OTHER_CPPFLAGS += -D__STDC_CONSTANT_MACROS
OTHER_CPPFLAGS += -D__STDC_LIMIT_MACROS
OTHER_CPPFLAGS += -DTARGET_POSIX
OTHER_CPPFLAGS += -DHAVE_LIBOPENMAX=2
OTHER_CPPFLAGS += -DOMX
OTHER_CPPFLAGS += -DOMX_SKIP64BIT
OTHER_CPPFLAGS += -DUSE_EXTERNAL_OMX
OTHER_CPPFLAGS += -DHAVE_LIBBCM_HOST
OTHER_CPPFLAGS += -DUSE_EXTERNAL_LIBBCM_HOST
OTHER_CPPFLAGS += -DUSE_VCHIQ_ARM
OTHER_CPPFLAGS += -DUSE_DISPMANX_TRANSFORM_T
OTHER_CPPFLAGS += -std=c++11
OTHER_CPPFLAGS += -pthread


# the C compiler on crosstools
CC      = $(HOME)bin/arm-none-linux-gnueabi-gcc

# the C++ compiler on crosstools
CXX     = $(HOME)bin/arm-none-linux-gnueabi-g++

# including the .h files
# -I (dash i) option tells the compiler where to find an external header (.h) file
INCLUDES  = ./
INCLUDES += $(RPI_ROOT)opt/vc/include
INCLUDES += $(RPI_ROOT)opt/vc/include/interface/vcos/pthreads
INCLUDES += $(RPI_ROOT)opt/vc/include/interface/vmcs_host/linux
INCLUDES += $(RPI_ROOT)usr/include

INCLUDES += $(RPI_ROOT)usr/include/cairo
INCLUDES += $(RPI_ROOT)usr/include/glib-2.0
INCLUDES += $(RPI_ROOT)usr/lib/arm-linux-gnueabihf/glib-2.0/include
INCLUDES += $(RPI_ROOT)usr/include/pixman-1
INCLUDES += $(RPI_ROOT)usr/include/freetype2
INCLUDES += $(RPI_ROOT)usr/include/libpng12
INCLUDES += $(RPI_ROOT)usr/include/gstreamer-1.0
INCLUDES += $(RPI_ROOT)usr/include/alsa
INCLUDES += $(RPI_ROOT)usr/include/gtk-2.0
INCLUDES += $(RPI_ROOT)usr/lib/arm-linux-gnueabihf/gtk-2.0/include
INCLUDES += $(RPI_ROOT)usr/include/atk-1.0
INCLUDES += $(RPI_ROOT)usr/include/gdk-pixbuf-2.0
INCLUDES += $(RPI_ROOT)usr/include/pango-1.0
INCLUDES += $(RPI_ROOT)usr/include/gio-unix-2.0/
INCLUDES += $(RPI_ROOT)usr/include/AL
# add OF libs
INCLUDES += $(OF_ROOT)libs/fmodex/include
INCLUDES += $(OF_ROOT)libs/glfw/include
INCLUDES += $(OF_ROOT)libs/glfw/include/GLFW
INCLUDES += $(OF_ROOT)libs/kiss/include
INCLUDES += $(OF_ROOT)libs/openssl/include
INCLUDES += $(OF_ROOT)libs/openssl/include/openssl
INCLUDES += $(OF_ROOT)libs/poco/include
INCLUDES += $(OF_ROOT)libs/rtAudio/include
INCLUDES += $(OF_ROOT)libs/tess2/include
INCLUDES += $(OF_ROOT)libs/openFrameworks
INCLUDES += $(OF_ROOT)libs/openFrameworks/utils
INCLUDES += $(OF_ROOT)libs/openFrameworks/app
INCLUDES += $(OF_ROOT)libs/openFrameworks/math
INCLUDES += $(OF_ROOT)libs/openFrameworks/sound
INCLUDES += $(OF_ROOT)libs/openFrameworks/types
INCLUDES += $(OF_ROOT)libs/openFrameworks/events
INCLUDES += $(OF_ROOT)libs/openFrameworks/gl
INCLUDES += $(OF_ROOT)libs/openFrameworks/graphics
INCLUDES += $(OF_ROOT)libs/openFrameworks/communication
INCLUDES += $(OF_ROOT)libs/openFrameworks/3d
INCLUDES += $(OF_ROOT)libs/openFrameworks/video

INCLUDES += $(RPI_ROOT)usr/lib/arm-linux-gnueabihf/gtk-2.0/include
INCLUDE_FLAGS= $(addprefix -I, $(INCLUDES))


# flags for the compiler : -pipe should make it use the filesystem less
CPPFLAGS	= $(DEBUG) -Wall $(OTHER_CPPFLAGS) $(INCLUDE_FLAGS) -MMD -MP

# copy the
# -L option tells the compiler where to find an external library
LDFLAGS  =
LDFLAGS += -L$(RPI_ROOT)opt/vc/lib
LDFLAGS += -L$(RPI_ROOT)usr/lib/arm-linux-gnueabihf
LDFLAGS += -L$(RPI_ROOT)usr/lib
LDFLAGS += -L$(RPI_ROOT)lib

# the static libraries that need linking
LDFLAGS += $(OF_ROOT)libs/kiss/lib/linuxarmv6l/libkiss.a
LDFLAGS += $(OF_ROOT)libs/rtAudio/lib/linuxarmv6l/libRtAudio.a
LDFLAGS += $(OF_ROOT)libs/tess2/lib/linuxarmv6l/libtess2.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoNet.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoData.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoNetSSL.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoCrypto.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoZip.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoUtil.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoXML.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoFoundation.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoNetSSL.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoNet.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoCrypto.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoUtil.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoXML.a
LDFLAGS += $(OF_ROOT)libs/poco/lib/linuxarmv6l/libPocoFoundation.a

# the extra flags for linking
LINK_FLAGS  =
LINK_FLAGS += -Wl,-rpath=./libs:./bin/libs
LINK_FLAGS += -Wl,-rpath-link,$(RPI_ROOT)usr/lib/arm-linux-gnueabihf:$(RPI_ROOT)usr/lib:$(RPI_ROOT)lib/arm-linux-gnueabihf:$(RPI_ROOT)lib
LINK_FLAGS += -Wl,--as-needed
LINK_FLAGS += -Wl,--gc-sections

# the linked libraries
# -l (lowercase L) tells the compiler the name of the library it needs to link
LDLIBS  =
LDLIBS += z
LDLIBS += dl
LDLIBS += X11
LDLIBS += gstapp-1.0
LDLIBS += gstvideo-1.0
LDLIBS += gstbase-1.0
LDLIBS += gstreamer-1.0
LDLIBS += gmodule-2.0
LDLIBS += gthread-2.0
LDLIBS += rt
LDLIBS += udev
LDLIBS += sndfile
LDLIBS += openal
LDLIBS += ssl
LDLIBS += crypto
LDLIBS += pulse-simple
LDLIBS += pulse
LDLIBS += asound
LDLIBS += gtk-x11-2.0
LDLIBS += gdk-x11-2.0
LDLIBS += atk-1.0
LDLIBS += gio-2.0
LDLIBS += pangoft2-1.0
LDLIBS += pangocairo-1.0
LDLIBS += gdk_pixbuf-2.0
LDLIBS += cairo
LDLIBS += pango-1.0
LDLIBS += freetype
LDLIBS += fontconfig
LDLIBS += gobject-2.0
LDLIBS += glib-2.0
LDLIBS += mpg123
LDLIBS += freeimage
LDLIBS += GLESv2
LDLIBS += GLESv1_CM
LDLIBS += EGL
LDLIBS += openmaxil
LDLIBS += bcm_host
LDLIBS += vcos
LDLIBS += vchiq_arm
LDLIBFLAGS = $(addprefix -l, $(LDLIBS))

# Find all the source files
SRC	= $(wildcard *.cpp)

# The list of .o files
OBJ = $(addprefix bin/,$(SRC:.cpp=.o))

# The compiled OF library
OF_LIB = $(OF_ROOT)libs/openFrameworksCompiled/lib/linuxarmv6l/libopenFrameworks.a



##### ACTIONS #####
all: info folder $(PROGRAM)

# A separate folder for .o files and the resulting app
folder:
	@mkdir -p bin

# Some info to debug
info:
	$(info --- INFO ---)
	$(info CC = $(CC))
	$(info CXX = $(CXX))
	$(info SRC = $(SRC))
	$(info OBJ = $(OBJ))
	$(info INCLUDE_FLAGS = $(INCLUDE_FLAGS))
	$(info CPPFLAGS = $(CPPFLAGS))
	$(info LDFLAGS = $(LDFLAGS))
	$(info LDLIBS = $(LDLIBS))

# LINK
$(PROGRAM): $(OBJ)
	@echo [ Link $(PROGRAM) ]
	$(CXX) -o $(PROGRAM) $(OBJ) $(OF_LIB) $(LINK_FLAGS) $(LDFLAGS) -pthread  $(LDLIBFLAGS)


# CLEAN
# cleans .o files and app, so that we really compile everything again
clean:
	@echo [ Clean ]
	rm -f  bin/*~ bin/._* bin/*.o bin/*.d bin/.DS_Store $(PROGRAM)

# COMPILE : create object files from source files
# .c is the prerequisite ($<) and .o the target ($@)
.c.o:
	@echo [ Compile $< ]
	$(CC) -c $(CPPFLAGS) -o $@ -c $<

.cpp.o:
	@echo [ Compile $< ]
	$(CXX) -c $(CPPFLAGS) -o $@ -c $<

# use this rule if you both have a .cpp and a .h file
bin/%.o: %.cpp %.h
	@echo [ Compile $< ]
	$(CXX) -c $(CPPFLAGS) -o $@ -c $<

# use this rule if you only have a .cpp
bin/%.o: %.cpp
	@echo [ Compile $< ]
	$(CXX) -c $(CPPFLAGS) -o $@ -c $<
