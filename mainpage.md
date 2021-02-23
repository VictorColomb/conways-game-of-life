Conway's Game of Life Documentation
====================================================

These webpages contain the documentation for Conway's game of life.

__Author:__ Victor Colomb (vic.col@hotmail.fr)

## Installation

To compile a ready to use solution, use:

```
make
```

To also compile test executables, use:

```
make compile-all
```

## Naive implementation

[Go to specific page.](@ref naive_implementation)

__Installation:__

To compile a ready to use naive solution, use:

```
make naive
```

To also compile test executables, use:

```
make naive-compile-all
```

__Usage:__

```
./app-naive-conway [-p|--print] ./[.../]source_file 
```

Conway's game of life naive implementation relies on a string of characters, following the convention: `0` for a live cell and `.` for a dead one. \n
The universe is of fixed size.

The initial state of the universe of given by a text file following the formatting:

```
{width} {height}
{number of steps}
The following lines contain the universe, according to the aforementionned convention.
```

An example for a simple glider follows:

```
6 6
100
.0....
..0...
000...
......
......
......
```

__Output:__

By default, the program will output PBM images in the `out` folder. \n
_Warning:_ The `out` folder will be emptied upon execution ! Be sure to empty it beforehand.

The `-p|--print` option will print each step to the console.
