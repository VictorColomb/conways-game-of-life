# Naive Implementation Documentation        {#naive_implementation}

## Usage

```
./app-naive-conway [-p|--print] ./[.../]source_file 
```

## Idea

Conway's game of life naive implementation relies on a string of characters, following the convention: `0` for a live cell and `.` for a dead one. \n
The universe is of fixed size.

## Input

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

## Output

By default, the program will output PBM images in the `out` folder. \n
_Warning:_ The `out` folder will be emptied upon execution ! Be sure to empty it beforehand.

The `-p|--print` option will print each step to the console.

## Files

- naive_universe.h and naive_universe.c define the naive universe structure
- naive_loader.h and naive_loader.c
