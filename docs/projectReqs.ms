.TL
Project Guidelines
.AU
Remus Africanus
.AI
University of North Southern
.NH
Use of C++11 (and later) features
.PP
As of yet, we have used:
.PP
.B "inline"
(C++17)
.PP
    The
.I "clip_rect"
function in the Collidable class is noted with this keyword.
.PP
.B "auto"
(C++11)
.PP
    Certainly saves a good deal of typing, at the expense of clarity.
An example appears at the start of the
.I "clip_dir"
function definition in the file
.I "Collidable.cpp",
where the local variables
.I "isect"
and 
.I "center"
are declared and initialized.
.PP
.B "enum class"
(C++11)
.PP
    Used in the Game class for the various game states.
.PP
.B "nullptr"
(C++11)
.PP
    Provides a type-safe value to assign to unused pointers.
.PP
.B "Range-based for loop"
(C++11)
.PP
   Line 150 in
.I "game.cpp"
.NH
STL Containers
.PP
.B "Vectors"
to hold players' and the level tiles' sprite maps,
amongst other things, of course.
.PP
.I "Dynamic sizing"
provided by vectors enabled convenient addition of new assets
as the project progressed, such as inserting the second player character's
sprite map once it was finally ready to go.
.NH
Use of Namespaces
.PP
We have one major namespace,
.B "fxx"
which encompasses all of the classes used in the game. This guards
against potential name conflicts with 3rd party libraries (e.g. SFML).
Each branch of the includes has its own respective namespace to further protect against name conflicts.
.PP
For example, "Game.h" and "Menu.h" are both under the "directors"
directory. Both of these classes also fall under the
.B "directors"
namespace.
.NH
Exception Handling
.PP
A rather elementary example,
but exception handling can be seen in the constructor of the menu class.
The code which attempts to open a font file is encompassed in a try block,
which upon failure will throw a C-string error message which is then
caught by the following catch block. At this point in development,
this is not believed to be a catastrophic error, so the program continues
on after displaying an error message to be noted by the engineers.
