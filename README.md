# Engine2D

2D engine game in SDL2
## 2D Game Engine 
This is a simple 2D game engine built using SDL2. It provides basic functionality for creating and managing game objects, handling input, and rendering graphics.

## Features
- Simple game object management
- Basic input handling
- Basic rendering using SDL2
- Basic collision detection
- Basic physics simulation
- Basic sound and music playback (not yet implemented)
- Basic animation support (not yet implemented)
- Basic UI support (not yet implemented)
- Basic scene management (not yet implemented)

## Installation
git clone this repository 
and then make

## Usage
Main things are in game folder in Game.cpp

### Game Loop
It's little complicated but works like normal SDL2 game Loop

### Game Object
GameObject is a class that represents a game object. It has a position, size, and velocity. It also has a list of components that can be added to it. Components are used to add functionality to the game object. For example, a sprite component can be used to render the game object on the screen.

### Input Handling
Input handling is done in Input class. It uses SDL2's event system to handle input events. The Input class provides methods for checking if a key is pressed, if a mouse button is pressed, and for getting the mouse position. It also provides methods for checking if a key was pressed or released in the current frame.

### Rendering
Rendering is done in the Renderer class. It uses SDL2's rendering system to render graphics on the screen. The Renderer class provides methods for drawing shapes, images, and text. It also provides methods for setting the draw color and clearing the screen.

### Collision Detection
Collision detection is using my SDL collision function between objects.

### Physics Simulation
It's done by simple gravity and velocity and can be changed as needed.

### Sound and Music Playback
It's not yet implemented.

### Animation Support
It's not yet implemented.

### UI Support
It's not yet implemented.

### Scene Management
It's not yet implemented.
