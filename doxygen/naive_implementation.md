# Naive Implementation Documentation {#naive_implementation}

The naive implementation of Conway's game of life uses a string to store the state of the universe's state, using the following convention:

* `.` represents a dead cell
* `o` represents a live cell

The information about the universe (width, height, number of simulation steps and cells' state) is stored in a \ref universe structure.

## Installation

* To compile a user-ready solution of the naive implementation, use `make naive`
* To compile all executables of the naive implementation, including tests, use `make naive-compile-all`

## Usage

* `app-naive-loader` to load a universe from a source textfile and print it as is to the console.

```bash
./app-naive-loader filename

Options:
  filename: source textfile (see formatting above)
```

* `app-naive-conway` to load a universe from a source textfile and execute the given amount of simulation steps.

```bash
./app-naive-conway [-ipt?] filename

Options:
  -i: generate image output for each step
  -p: print simulation steps to the console
  -t: consider the universe as a torus
  -?: print source textfile formatting help
  filename: source textfile to load the universe from
```
