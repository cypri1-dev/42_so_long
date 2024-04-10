##
<h1 align="center"> <img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-so_long-bonus.png?raw=true"> </h1> 

## Description
so_long is a "collect the coins" style game project developed as part of the curriculum at Ecole 42. Players control a character tasked with collecting objects while navigating obstacles. The game utilizes the MinilibX library for an interactive graphical interface. Objectives include image manipulation, handling user events, and creating custom game maps from text files.

![GIF](https://github.com/cypri1-dev/42_so_long/blob/main/screen_gif/so_long.gif)

## Project Components Table
The following table describes the various components and files included in the so_long project:

| File/Header File/Folder     | Description                                                                                         |
|----------------------|-----------------------------------------------------------------------------------------------------|
| `img`                | This folder contains images used in the program's graphical interface.                             |
| `sources/display`    | This folder contains functions responsible for rendering graphics and displaying elements on the screen. |
| `sources/end_game.c` | Contains functions responsible for handling end game scenarios and displaying relevant information or messages to the player. |
| `sources/map`        | Contains functions related to the management and manipulation of game maps, including parsing and modifying map data. |
| `sources/movements`  | This folder contains functions related to handling character movements within the game, including functions for controlling player movement and handling collisions with obstacles. |
| `sources/so_long.c`  | Main program file responsible for initializing the game, managing the game loop, and handling user input. |
| `TESTS`              | This folder contains tests maps used in the game  |
| `libft_so_long`      | A directory containing the Libft library, used for some auxiliary functions.                        |
| `Makefile`           | The Makefile script for automating project compilation.                                            |

## Map Example
```bash
1111111111111
1000001000001
10P0000000001
1000000100001
1000000000001
10000001M0C01
1000000000001
1000000000001
1000000000001
1000M00000001
100C00000E001
1000000000001
1111111111111
```
  - `1` represents a wall.
  - `0` represents an empty space.
  - `P` represents the character.
  - `C` represents a collectible
  - `M` represents a monster.

## Installation and Compilation
1. Clone this repository into your project:
```bash
git clone https://github.com/cypri1-dev/42_so_long.git
cd 42_so_long
```
## How to use ?
```bash
./so_long TESTS/[*.ber]
```
## Features

1. **Interactive Graphical Interface:** Utilizes the MinilibX library to create an interactive graphical interface for the game.
   
2. **Character Control:** Allows the player to control a character using the keyboard's arrow keys.
   
3. **Custom Maps:** Supports reading custom game maps from specific format text files.
   
4. **Object Collection:** Implements the mechanic of collecting objects scattered throughout the map by the main character.
   
5. **Collision Handling:** Manages collisions between the character and walls as well as other elements on the map.
   
6. **Information Display:** Displays the number of objects collected and the number of movements made by the player.
   
7. **Victory/Defeat Messages:** Displays a victory message when all objects have been collected and a defeat message in case of collision with an obstacle or enemy.
   
8. **Animations:** Integrates animations to make character movement and object collection more fluid and dynamic.
   
9. **Difficulty Levels:** Supports the creation of variable difficulty levels by modifying the arrangement of objects and obstacles on the map.
