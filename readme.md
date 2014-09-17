# Cross compiling OpenFrameworks 0.8.4 for Raspberry Pi on XCode and OSX

This is a work in progress. It's still a big mess, but it works. Compile openframeworks for Raspberry Pi on your Mac running OSX Mavericks from XCode5

** ! Please use this at your own risk ! **



## Setup instructions

#### 1 XTools Toolchain

Create a case sensitive disk image (.dmg) file with the crosstools toolchain for OSX following this guide:  <http://www.jaredwolff.com/blog/cross-compiling-on-mac-osx-for-raspberry-pi/> 

You don't really need to compile the toolchain yourself. It's complicated and takes some time. Jared Wolff has been kind enought to already provide a compiled toolchain that you can download here: <http://www.jaredwolff.com/toolchains/>

Don't make the disk image too small, you'll need to copy some more stuff into it later.
Jared Wolff suggests a 256Mb disk image, but i'm using 2Gb.

You will end up with a dmg containing the full toolchain. When you mount it, you'll be able to access it from eg. `/Volumes/xtools/`



#### 2 Setup OF on the raspberry pi.

Download the latest OF release for linux armv6 Raspberry Pi from the downloads page:
<http://openframeworks.cc/download/>

(I'm working with OF_v0.8.4 right here <http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_linuxarmv6l_release.tar.gz>)

And read the getting started instructions to make it work on your RPI
<http://openframeworks.cc/setup/raspberrypi/Raspberry-Pi-Getting-Started.html>
Follow the easy steps on this page and make sure you can compile the "openFrameworksCompiled" project. (This will take a while)

Compile and run at least one of the examples include to make sure you've set up OF on the Pi correctly.


#### 3 Setup Samba on the Pi

Samba allows you to access the Pi from your Mac over the network. For example making the root of the pi accessible from `/Volumes/Pishare` on your Mac...

(TODO! full explanation)

#### 4 Copy openframeworks from the Pi to your Mac

Copy the whole OpenFrameworks folder (including the compiled libraries) from your RPI to your mac, this will be your working directory for OF, just like the one you normally use on your mac. 


#### 5 Copy /usr from the RPI to your Mac

From the Pi to `/Volumes/xtools/` on your mac:

	/usr/include
	/usr/lib

for example:

	cp -R -v /Volumes/PiShare/usr/include Volumes/xtools/arm-none-linux-gnueabi/usr/include
	cp -R -v /Volumes/PiShare/usr/lib Volumes/xtools/arm-none-linux-gnueabi/usr/lib

You might have to change permissions on the copied folders.


#### 6 Fix the absolute paths in /usr

There are a few bad symlinks and .so files in the `/usr` folder you copied from your Pi to the Xtools disk image. (`/Volumes/xtools/arm-none-linux-gnueabi/usr`)
When trying to compile, they create annoying, mesmerising and confusing compilation errors like this:

	ld: cannot find -lgtk-x11-2.0
	ld: cannot find -lgdk-x11-2.0
	
	ld: cannot find /lib/arm-linux-gnueabihf/libpthread.so.0
	ld: cannot find /usr/lib/arm-linux-gnueabihf/libpthread_nonshared.a
	
	ld: cannot find /lib/arm-linux-gnueabihf/libc.so.6
	ld: cannot find /usr/lib/arm-linux-gnueabihf/libc_nonshared.a
	ld: cannot find /lib/arm-linux-gnueabihf/ld-linux-armhf.so.3
	
	`dlsym': (.text+0xc): undefined reference to `__dlsym'
	libdl.so.2: could not read symbols: Invalid operation


You'll need the absolute paths in those files and the bad symlinks.
Do not touch the ones on your Pi, only the ones in `/Volumes/xtools`!

I had to fix these:
	
	usr/lib/arm-linux-gnueabihf/libgtk-x11-2.0.so
	usr/lib/arm-linux-gnueabihf/libgdk-x11-2.0.so
	usr/lib/arm-linux-gnueabihf/libpthread.so
	usr/lib/arm-linux-gnueabihf/libc.so
	usr/lib/arm-linux-gnueabihf/libz.so
	usr/lib/arm-linux-gnueabihf/libm.so
	usr/lib/arm-linux-gnueabihf/libglib-2.0.so
	usr/lib/arm-linux-gnueabihf/libpng12.so
	usr/lib/arm-linux-gnueabihf/libdl.so
	usr/lib/arm-linux-gnueabihf/libcrypt.so
	usr/lib/arm-linux-gnueabihf/librt.so
	usr/lib/arm-linux-gnueabihf/libthread_db.so
	usr/lib/arm-linux-gnueabihf/libusb-1.0.so
	usr/lib/arm-linux-gnueabihf/libutil.so
	
	
Some of them are files (you can just edit with a text editor), other ones are symlinks that link to an absolute path. 

Find the bad symlinks by typing

	ls -l
	
Symlinks with a target starting with `/` are bad since they refer to a path outside of your xtools disk. For example

	libpng12.so -> /lib/arm-linux-gnueabihf/libpng12.so.0

Delete the bad ones an relink to a correct relative path like this (from inside `/Volumes/xtools/arm-none-linux-gnueabi/usr/lib/arm-linux-gnueabihf`)

	cd /Volumes/xtools/arm-none-linux-gnueabi/usr/lib/arm-linux-gnueabihf
	unlink ./libpng12.so
	ln -s ../../../lib/arm-linux-gnueabihf/libpng12.so.0 ./libpng12.so


#### 7 copy the example project and test it

copy the RPI OF OSX Crosscompile example to the right place and build it from XCode

* Build by pressing `cmd+B`
* Clean by pressing `cmd+Shift+K`


### TO BE CONTINUED AND PERFECTED
Still a lot of cleaning to be done, this was a rushed job.

