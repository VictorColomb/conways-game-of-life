# Conway's Game of Life

Conway's game of life follows the following rules:

* A dead cell will become alive in the next step if it has exactly three alive neighbors
* An alive cell will become dead in the next step of it has less than one or more than four (both included) alive neighbors

Neighbors are the eight surrounding cells (vertically, horizontally and diagonally).

We provide a naive implementation for the simulation universe using a string to store the universe cells (see detailed information [here](https://viccol961.github.io/IN101_project/naive_implementation.html)).

## Installation

In the terminal:

* To compile a user-ready solution, use `make`
* To compile a user-ready solution of the naive implementation, use `make naive`
* To compile all executables, including tests, use `make compile-all`
* To compile all executables of the naive implementation, including tests, use `make naive-compile-all`

## Usage

### Source textfiles

Universes are loaded from text files formatted as follows:

```text
width height
number_of_steps
universe_cells_state
```

where universe cells follow the convention `.` for a dead cell and `o` for a live one.

Here's an example for a `3x4` universe:

```text
3 4
3
.o..
..o.
ooo.
```

### Command-line usage

* `app-naive-loader` to load a universe from a source textfile and print it as is to the console.

```bash
./app-naive-loader filename

Options:
  filename: source textfile (see formatting above)
```

* `app-naive-conway` to load a universe from a source textfile and execute the given amount of simulation steps

```bash
./app-naive-conway [-ipt?] filename

Options:
  -i: generate image output for each step
  -p: print simulation steps to the console
  -t: consider the universe as a torus
  -?: print source textfile formatting help
  filename: source textfile to load the universe from
```

## Tests

We provide a series of tests to verify that all the provided function work properly. \n
Use `make launch-test` to execute them all.

See detailed information on the related page [here](https://viccol961.github.io/IN101_project/tests.html).

## Additional features

See detailed information on the related page [here](https://viccol961.github.io/IN101_project/additional_features.html).

* Options parser for `app-naive-conway`.
* Possibility to consider the universe as a torus.
* Decided to use PBM standard for the output images instead of the PPM standard.
