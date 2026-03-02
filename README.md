*This project has been created as part of the 42 curriculum by mrojouan*

## Description

**so_long** is a 2D game project that challenges you to create a simple educational game using the MinilibX graphics library. The game involves:

### Project Goal
Create a small 2D game where a player must collect all items on a map and reach an exit, using only window management and image display in C.

### Overview
The project demonstrates:
- **Map parsing** from `.ber` files with validation
- **Game state management** using structures
- **Graphics rendering** with textures and sprites (wall, floor, collectible items, player, exit)
- **Player movement** via keyboard input (Arrow keys)
- **Collision detection** and pathfinding validation
- **Game logic** including move counting and win conditions

## Features

- **Map validation**: Ensures the map is rectangular, surrounded by walls, and contains exactly one player and one exit
- **Path verification**: Uses flood filling algorithm to verify that the exit and all collectibles are reachable from the player's starting position
- **Graphics rendering**: Displays the game with tile-based textures
- **Move counter**: Tracks the number of moves the player makes
- **Input handling**: Responsive keyboard controls

## Instructions

### Compilation

Compile the project using the provided Makefile:

```bash
make
```

This will:
1. Compile all source files
2. Build the MinilibX library (if needed)
3. Link all necessary libraries (X11, Xext, lm, lz)
4. Generate the executable `so_long`

To clean object files:
```bash
make clean
```

To remove all generated files including the executable:
```bash
make fclean
```

To rebuild from scratch:
```bash
make re
```

### Execution

Run the game with a valid map file:

```bash
./so_long maps/map.ber
```

or

```bash
./so_long maps/map2.ber
```

**Map file requirements** (`.ber` format):
- Must be rectangular
- Must be surrounded by walls ('1')
- Must contain exactly one player ('P')
- Must contain exactly one exit ('E')
- Must contain at least one collectible ('C')
- Floor tiles are represented by ('0')
- Any other character is invalid

### Controls

- **Arrow Keys** : Move the player
- **ESC** or click the window close button: Exit the game

## Project Structure

```
so_long/
├── so_long.c                 # Main program
├── so_long.h                 # Header file with structures and function declarations
├── Makefile                  # Build configuration
├── maps/                     # Example map files
│   ├── map.ber
│   └── map2.ber
├── game/                     # Game logic
│   ├── init_game.c          # Game initialization and rendering
│   ├── exit_window.c        # Exit/cleanup handling
│   └── key_press.c          # Keyboard input handling
├── parsing_helper/          # Map parsing and validation
│   ├── parsing.c            # Main parsing logic
│   ├── map_filler.c         # File reading and map loading
│   ├── verif.c              # Map validation checks
│   ├── check_path.c         # Pathfinding validation
│   ├── flood_fill.c         # Flood fill algorithm
│   ├── get_position.c       # Player position detection
│   ├── errors.c             # Error handling
│   └── utils.c              # Utility functions
├── get_next_line/           # Custom line reading utility
│   ├── get_next_line.c
│   ├── get_next_line.h
│   └── get_next_line_utils.c
├── mlx/                     # MinilibX graphics library
└── texture/                 # Game texture/sprite files (if any)
```

## Technical Details

### Dependencies
- **MinilibX**: Graphics library for X11 window management
- **X11 libraries**: Xext, lm, lz for graphics rendering
- **C Standard Library**: For memory management and utilities

### Key Data Structure
```c
typedef struct s_game
{
    void    *wall;           // Texture for walls
    void    *floor;          // Texture for floor
    void    *player;         // Texture for player
    void    *collect;        // Texture for collectibles
    void    *exit;           // Texture for exit
    int     tile_width;      // Width of one tile
    int     tile_height;     // Height of one tile
    char    **map;           // 2D map array
    int     player_count;    // Validation: should be 1
    int     exit_count;      // Validation: should be 1
    int     consum_count;    // Number of collectibles
    int     move_count;      // Current move counter
    int     width;           // Map width in tiles
    int     height;          // Map height in tiles
    int     player_y;        // Player Y position
    int     player_x;        // Player X position
    void    *mlx;            // MinilibX instance
    void    *window;         // Game window
}   t_game;
```

## Example Map Format

```
1111111111
1P0000E001
1010101001
1001C00001
1111111111
```

Where:
- `1` = Wall
- `0` = Floor (walkable)
- `P` = Player starting position
- `E` = Exit
- `C` = Collectible item

## Resources

### Official Documentation
- [MinilibX Documentation](https://github.com/42Paris/minilibx-linux) - Graphics library
- [X11 Documentation](https://www.x.org/wiki/) - Window system
- [C Standard Library Reference](https://en.cppreference.com/w/c) - Standard C functions

### Relevant Topics
- **Flood Fill Algorithm**: [Wikipedia - Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
- **Game State Management**: Classic approach for managing game objects and states
- **Event-Driven Programming**: X11 event handling

### Tutorials & References
- MinilibX tutorials from 42 school resources
- C memory management and struct organization
- Event loop and input handling in graphics applications

## AI Usage

**Note**: This project was developed following 42 school curriculum guidelines and best practices. If AI tools were used during development, typical applications would include:

- **Code review and optimization**: Suggestions for improving code structure
- **Documentation generation**: Assistance with README and comments
- **Debugging assistance**: Help identifying logic errors
- **Algorithm explanation**: Understanding the flood fill algorithm for pathfinding validation

Any AI-generated code was reviewed and integrated to maintain the project's integrity and adherence to 42 standards.

## Notes

- The project uses only allowed functions from the 42 school norm
- All memory allocations are properly freed
- The code follows the 42 school coding standard (norm)
- The program handles errors gracefully and exits cleanly
