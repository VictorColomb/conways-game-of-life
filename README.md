# Conway's Game of Life Documentation

## General

Conway's game of life follows the following rules:

* A dead cell will become alive in the next step if it has exactly three alive neighbors
* An alive cell will become dead in the next step of it has less than one or more than four (both included) alive neighbors

Neighbors are the eight surrounding cells (vertically, horizontally and diagonally).

We provide a naive implementation for the simulation universe using a string to store the universe cells (see detailed information [here](https://viccol961.github.io/IN101_project/naive_implementation.html)) as well as a linked list implementation featuring an option for the universe to be expandable (see detailed information [here](https://viccol961.github.io/IN101_project/linkedlist_implementation.html)).

## Installation

In the terminal:

* To compile a user-ready solution, use `make`
* To compile a user-ready solution of the naive implementation, use `make naive`
* To compile a user-ready solution of the linked list implementation, use `make linkedlist`
* To compile all executables, including tests, use `make compile-all`
* To compile all executables of the naive implementation, including tests, use `make naive-compile-all`
* To compile all executables of the linked list implementation, including tests, use `make linkedlist-compile-all`

## Usage

### Source textfiles

Universes are loaded from text files formatted as follows:

```none
width height
number_of_steps
universe_cells_state
```

where universe cells follow the convention `.` for a dead cell and `o` for a live one.

Here's an example for a `3x4` universe:

```none
3 4
3
.o..
..o.
ooo.
```

### Command-line usage

* `app-naive-loader` to load a universe from a source textfile and print it as is to the console, using the naive implementation.

```bash
./app-naive-loader filename

Options:
  filename: source textfile (see formatting above)
```

* `app-naive-conway` to load a universe from a source textfile and simulate the given amount of steps, using the naive implementation.

```bash
./app-naive-conway [-ipt?] filename

Options:
  -i: generate image output for each step
  -p: print simulation steps to the console
  -t: consider the universe as a torus
  -?: print source textfile formatting help
  filename: source textfile to load the universe from
```

* `app-list-loader` to load a universe from a source textfile and print it as is to the console, using the linked list implementation.

```bash
./app-list-loader filename

Options:
  filemane: source textfile
```

* `app-list-conway` to load a universe from a source textfile and simulate the given amount of steps, using the linked list implementation.

```bash
./app-list-conway [-ipte?] filename

Options:
  -i: generate image output for each step
  -p: print simulation steps to the console
  -t: consider the universe as a torus
  -e: consider the universe as expandable (incompatible with a torus universe!)
  -?: print source textfile formatting help
  filename: source textfile to load the universe from
```

### Build and run

Use `make run-<app_name> [ARGS=""]` to build and run an executable (`make run-test-naive-conway` or `make run app-list-conway ARGS="-i file.txt"` for example).

Use `make valgrind-<app_name> [ARGS=""]` to build and run an executable under the `valgrind` tool.

## Tests

We provide a series of tests to verify that all the provided function work properly.  
Use `make launch-test` to execute them all.

See detailed information on the related page [here](https://viccol961.github.io/IN101_project/tests.html).

## Additional features

See detailed information on the related page [here](https://viccol961.github.io/IN101_project/additional_features.html).

* Options parser for `app-naive-conway` and `app-list-conway`
* Possibility to consider the universe as a torus for both the naive and linked list implementation
* Possibility to consider the universe as expandable for the linked list implementation.
* Decided to use PBM standard for the output images instead of the PPM standard.
