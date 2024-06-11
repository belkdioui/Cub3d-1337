# Cub3D

Cub3D is a simple 3D game engine inspired by Wolfenstein 3D, created as part of the 42 Network curriculum. This project implements a basic ray-casting algorithm to render a 3D environment from a first-person perspective using the MiniLibX graphics library.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Project Structure](#project-structure)
- [Screenshots](#screenshots)
- [Map Format](#map-format)
- [Acknowledgements](#acknowledgements)

## Features

- Basic ray-casting engine to render a 3D environment
- Texture mapping for walls
- Simple sprite rendering
- Basic collision detection
- Keyboard controls for movement

## Getting Started

### Prerequisites

- GCC (or another C compiler)
- Make
- X11 development libraries (for MiniLibX) ```sudo apt install libmlx-dev```
- Git (for cloning the repository)

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/cub3d.git
    cd cub3d
    ```

2. Build the project:
    ```sh
    make
    ```

## Usage

To run the game:
```sh
./cub3d maps/map.cub
```

## Controls

- `W`: Move forward
- `S`: Move backward
- `A`: Strafe left
- `D`: Strafe right
- `Left Arrow`: Turn left
- `Right Arrow`: Turn right
- `ESC`: Exit the game

## Project Structure

- `src/`: Source files
- `includes/`: Header files
- `textures/`: Texture files
- `maps/`: Example map files
- `Makefile`: Build configuration

## Screenshots

<img width="1919" alt="Screen Shot 2024-06-11 at 10 40 09 AM" src="https://github.com/belkdioui-111/cub3d/assets/76043881/99f047fe-b30b-4e05-8c94-dfe153d20a2b">

<img width="348" alt="Screen Shot 2024-06-11 at 10 40 41 AM" src="https://github.com/belkdioui-111/cub3d/assets/76043881/4e40b91e-a511-45e4-be31-202688705473">

## Map Format

The game uses a custom .cub format to define the map layout. Each line specifies information about the walls, floors, ceilings, and player starting position.


## Acknowledgements

- The 42 Network for the project inspiration
- MiniLibX library creators

