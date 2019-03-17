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
.B "auto"
(C++11)
Because we could.
.PP
.B "enum class"
(C++11)
.PP
.B "nullptr"
(C++11)
Because we should!
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
A rather elementary example, but exception handling can be seen a
constructor of the menu class. The code which attempts to open a font
file is encompassed in a try block, which upon failure will throw a
C-string error message which is immediately caught by the following catch 
block. At this point in development, this is not believed to be a 
catastrophic error, so the program continues on after displaying an 
error message for the engineers.
