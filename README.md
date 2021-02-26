# Conway's Game of Life Documentation

## Installation

To compile a ready to use solution, use:

```[bash]
make
```

To also compile test executables, use:

```[bash]
make compile-all
```

## Naive Implementation

__Installation:__

To compile a ready to use naive solution, use:

```[bash]
make naive
```

To also compile test executables, use:

```[bash]
make naive-compile-all
```

__Usage:__

```[bash]
./app-naive-conway [-p|--print] ./[.../]source_file 
```

Conway's game of life naive implementation relies on a string of characters, following the convention: `0` for a live cell and `.` for a dead one. \n
The universe is of fixed size.

The initial state of the universe of given by a text file following the formatting:

```[txt]
{width} {height}
{number of steps}
The following lines contain the universe, according to the aforementionned convention.
```

An example for a simple glider follows:

```[txt]
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

The `-p|--print` option will print each step to the console.
