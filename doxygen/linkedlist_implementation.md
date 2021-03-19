# Linked List Implementation Documentation {#linkedlist_implementation}

The linked list implementation of Conway's game of life uses, unsurprisingly, a linked list to store the alive cells of a universe.

Each cell is of the following structure:

```c
struct linked_cell
{
  int row;
  int column;
  linked_cell* next;
}
```

## Installation

* To compile a user-ready solution of the linked list implementation, use `make linkedlist`
* To compile all executables of the linked list implementation, including tests, use `make linkedlist-compile-all`

# Usage

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
