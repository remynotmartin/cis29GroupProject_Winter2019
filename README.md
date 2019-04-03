# Jump, jump!

A very incomplete game project. It is a two-player runner with randomly generated levels. The collisions or the physics update are done incorrectly and cause glitches such as the player clipping into walls.

## Requirements

Requires [SFML](https://www.sfml-dev.org/). Optionally, the project can be built using make.

## Build instructions

### Linux

Install GNU make, gcc, and SFML. Run make in the root of the project.

### Mac

Same as Linux.

### Windows (Visual Studio)

Make a new empty C++ project.
Set mode to Release.
Set up SFML like they describe on the SFML website.
Move the files into the project folder.
Drag the src folder into the "Source Files" filter.
Drag the include folder into the "Header Files" filter.
Right click the project and go to the project properties.
Make sure mode is Release.

In C/C++ > General:
Put the project folder\include as an additional include directory.

In Linker > General:
Put the project folder\lib as an additional library directory.

In Linker > Input:
Add Actors.lib as an additional dependency.

Build.

## Level editor

To use custom levels, pass 0 as a command-line argument.

To use save a level from the level editor, press the dump button and paste the string in the dump.py utility. Python required.
