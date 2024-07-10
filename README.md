# So_Long Project

## Description
So_Long is a project that involves creating a simple game using the MiniLibX graphics library. The game implements a grid-based map where the player navigates to reach a goal while avoiding obstacles.

## Files

- **get_next_line.c**: Line reading function used to read maps from map files.
- **get_next_line_utils.c**: Utility functions for `get_next_line.c`.
- **so_long.c**: Main function of the game, handling overall game logic.
- **so_long_outil.c**: Utility functions for `so_long.c`.
- **read_map.c**: Functions for parsing and reading map files.

### Image Directories

- **i/**: Contains XPM images used as textures for in-game objects.
  - `img1.xpm`, `img2.xpm`, `img3.xpm`, `poke.xpm`

- **p/**: Contains XPM images used as textures for in-game characters and elements.
  - `a1.xpm`, `a.xpm`, `d1.xpm`, `d.xpm`, `s1.xpm`, `s.xpm`, `w1.xpm`, `w.xpm`

## Compilation and Usage

### Compilation
To compile the So_Long project, use the provided Makefile. Execute the following command:
```sh
make
```

## Execution
Run the executable with the map file as an argument:

```sh
./so_long map.ber
```
Replace map.ber with the actual map file you want to load.

## Contributors
[pschemit](https://github.com/pschemit)
