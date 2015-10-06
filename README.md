/* \mainpage ManuvrOS Documentation

        __  ___                             ____  _____ 
       /  |/  /___ _____  __  ___   _______/ __ \/ ___/ 
      / /|_/ / __ `/ __ \/ / / / | / / ___/ / / /\__ \  
     / /  / / /_/ / / / / /_/ /| |/ / /  / /_/ /___/ /  
    /_/  /_/\__,_/_/ /_/\__,_/ |___/_/   \____//____/   


A cross-platform real-time, event-driven "Operating System" for asynchronous applications. It was intended to make it easier to write asynchronous, cross-platform IoT applications.

![ManuvrOS](doc/3d-logo.png)


----------------------
####What is in this repository:
**./doc**:  Documentation related to this project. The code base is being converted to doxygen. It can be [viewed online](http://manuvr.io:8080/), but will not be guaranteed to be what you have in front of you. The doc can be built with the command...

    make docs

**./demo**:  Demonstration of ManuvrOS built as an application framework under linux. 

**./StringBuilder**:  The StringBuilder library.

**./DataStructures**:  Various templates for data structures.
    
**./ManuvrOS**:  The ManuvrOS source code. Also contains ports from other people's libraries. This is noted where it occurs.


----------------------
####If you intend on using ManuvrOS in an Arduino-esque environment...
You will need to copy the following directories into your IDE's library directory:
-   ManuvrOS
-   DataStructures
-   StringBuilder

Each library has an examples directory that ought to be visible from the IDE when properly installed.

Additionally, to overcome the Arduino library-within-library limitation, please follow [these instructions](http://www.joshianlindsay.com/index.php?id=147) to make your IDE treat gcc a little better:

StringBuilder and the DataStructure templates will all build and be usable without the include fix, but ManuvrOS is too complicated to fit within the constraints of the IDE's default behavior.


----------------------
####If you intend on using ManuvrOS as an application framework in a "big" environment (such as a Raspberry Pi, or desktop)

At this point, you would have to integrate (or link) the source into your project how you see fit. To see an example RasPi project, please refer to the **demo** directory.
It doesn't do much, but it should be able to read the i2c sensors that are currently supported. The demo application was intended to be built on a RasPi, so it makes a hard-coded
attempt to open /dev/i2c-1. The demo application will get better as things settle down. 

You can build the demo application with

    make
    
or

    make testbench

...for the same thing with debug symbols.


----------------------
Bitcoin accelerates feature requests and bug fixes. :-)

**19fZqFWGUqb9u6AQTk71AXP8hBHnyxWK3X**


----------------------
####High-level TODO list
-   Link against libuv for "big" builds so we can handle threading on android, windows, linux, etc. without having to hurt ourselves.
-   Clean up the unit tests that exist, and merge in some that aren't in the testbench yet.
-   Make the testbench do something interesting.
-   Investigate usage as an application framework under RTOS.
-   Verify that ManuvrOS works correctly when built as 64-bit.
-   Add callgrind support to the Makefile.
-   Write an autoconf script to choose target and features, detect env, etc...


----------------------
####License
Original code is GPL v2. 

Code adapted from others' work inherrits their license terms, which were preserved in the commentary where it applies. 

----------------------
####Cred:
The ASCII art in this file was generated by [this most-excellent tool](http://patorjk.com/software/taag).

Some of the hardware drivers are adaptions from Adafruit code. This is noted in each specific class so derived.

*/
