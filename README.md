Hypotrochoid Spirograph

<img width="939" height="937" alt="SpiroBoi2" src="https://github.com/user-attachments/assets/61992c82-c018-4550-b990-1f5c8eb560af" />

A real-time, interactive hypotrochoid spirograph simulator built in C++ using raylib.

The program simulates a small circle rolling around the inside of a larger circle while a pencil attached to the smaller circle traces out a geometric pattern. Users can adjust the circle sizes and pencil distance in real time to create different spirograph designs.

Preview

The simulation features:

A large stationary circle.
A smaller circle rotating along the inside of the larger circle.
An animated pencil attached to the smaller circle.
A continuously drawn trail that creates the spirograph pattern.
Real-time parameter adjustments through keyboard controls.
Built With
C++ – Core programming language.
raylib – Graphics rendering, window management, and keyboard input.
raymath – Mathematical utilities, including value clamping.
Standard Library – Uses std::vector to store the pencil's previous positions.
Getting Started
Prerequisites

Before running the project, make sure you have:

A C++ compiler supporting C++11 or later.
raylib installed and configured.
A compatible build environment.
Compilation

Compile the source file using a command similar to:

bash
g++ main.cpp -o Spirograph -lraylib -lopengl32 -lgdi32 -lwinmm


Note: The linking flags above are intended for Windows with MinGW. Other operating systems may require different linking flags.

Running

After compiling, run the executable:

bash
./Spirograph


On Windows:

bash
Spirograph.exe

Controls

All parameters can be adjusted while the simulation is running.

Key	Action
R	Increase large circle radius (R)
F	Decrease large circle radius (R)
T	Increase small circle radius (r)
G	Decrease small circle radius (r)
Y	Increase pencil distance (d)
H	Decrease pencil distance (d)
C Change spirograph color
SPACE	Reset all parameters to default values
Adjustable Parameters
Parameter	Default	Description
R	280	Radius of the stationary outer circle
r	90	Radius of the smaller rotating circle
d	60	Distance between the small circle's center and the pencil tip

The simulation uses clamping to prevent invalid parameter values:

R: 10–450
r: 5–(R - 5)
d: 0–400

Whenever a parameter is changed, the existing drawing is cleared and the animation rest
