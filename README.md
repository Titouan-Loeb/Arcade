# Arcade
## What is Arcade?
Arcade is C++ reproduction of an arcade game. The are two game available:
- Pacman
- Nibler

You can play those two game using 3 different graphical libraries:
- ncurses
- SDL2
- SFML

## Compile
The project compiles with make, use the make command:
```bash
make
```
To compile the game and the libraries. Make sur you have the make command, the ncurses, the sld2 and the SFML installed on your machine.

## Run
Once you compiled the program choose the graphical library you want to use, there are located in the lib folder:
- lib/arcade_ncurses.so
- lib/arcade_sdl2.so
- lib/arcade_sfml.so

And run the program like so:
```bash
./arcade [graphical-library.so]
```
## Games
### Pacman
Do I really need to present what is pacman?
Well in case you were born after 2010, pacman is a game where you control a yellow character that has to travel through a maze collection the coins while avoiding ghosts that want to dead. You have 3 lives. To help you there are power ups in each coner of the map, the power up makes the ghosts vulnerable for a short period of time which allow you to eat them, they will be sent to their base and they will revive after few seconds.

### Nibler
In Nibler you control a snake and you have to collect coins inside a maze, your body grows each time you collect a coin. You must collect all the coins without touching your tail.

### ✨ Have fun! ✨