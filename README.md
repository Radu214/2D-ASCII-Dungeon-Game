# 2D ASCII Dungeon   Game

## Overview
This is a simple, text-based game where the player navigates through randomly generated rooms, facing off against
enemies in each room.

## Features

- **Randomly Generated Rooms:** Each room is unique, providing a different layout and challenge every time.
- **ASCII Graphics:** Simple, text-based graphics.
- **Enemy Encounters:** Face off against an enemy in each room. Defeat the enemy to proceed to the next room.
- **Infinite Levels:** The game continues indefinitely.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang)

### Installation

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/Radu214/2D-ASCII-Dungeon-Game
   cd 2D-ASCII-Dungeon-Game

2. **Build the Project:**
    ```sh
    g++ -o dungeon.exe main.cpp

3. **Run the Game:**
    ```sh
    ./dungeon

## Gameplay

Defeat the enemy in the current room to move on to the next one. The goal is to survive and defeat as many enemies as possible.

1. **Controls:**

    The player is marked with the `x` character. Use `w`, `a`, `s`, `d` to move and `e` to shoot. Note: You can only shoot to your right, and can't shoot again until the bullet has hit the enemy, a wall, a trap, or the map's edge.

2. **Game Elements:**

    - The traps are marked with `@`. Going through them will take 1 life-point.
    - The walls are marked with `#`. While the player can't go through the walls, the enemy can.
    - The enemy is marked with `$` and spawns in a random location in each room. The enemy will try and chase the player, killing the player instantly. Note: the enemy moves slower than the player.

The first room is the tutorial. While the traps will still take 1 life-point when walking over them, the enemy doesn't do any damage.

## Additional Notes

This is a game I made when I was in high-school and it can be improved in many ways.


