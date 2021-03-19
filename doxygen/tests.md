# Tests Documentation {#tests}

We provide tests for all implemented functions. \n
Compile and launch all tests using `make launch-tests`.

## Tests for the naive implementation

### Naive universe structure

test-naive-universe.c

* `naive_universe_get_cell`: the test creates a universe from a string constant and checks that the function applied to three different cells returns the correct character.
* `naive_universe_print`: the test prints a universe to the console, the user has to verify that the printing is correct.
* `naive_update_cell`: the test updates a cell of a universe and verifies the new string.

### Naive loader

test-naive-loader.c

* `naive_conway_load`: the test will attempt to load the universe from `data/glider.txt` and will check that the parameters of the returned structure are correct.

### Naive universe simulator

test-naive-conway.c

* `naive_count_neighbor`: the test will load the universe from `data/glider.txt` and checks several neighbor counts with and without considering the universe as a torus.
* `naive_step`: the test will use the `data/archive-test` directory that contains 512 source textfiles and their next step solution. \n
  It will load each universe from its corresponding file, use the `naive_step` function and compare the return's cell table with the given exact solution.

### Naive PBM image generator

test-naive-generate-image.c

* `naive_pgm_generate`: the test will load `data/glider.txt` universe and generate the associated image.

## Tests for the linked list implementation

### Linked list implementation and list universe structure

test-list-universe.c

* `linked_list_insert`: the test will create a list using the function and check each cell's elements against a hardcoded list.
* `linked_universe_get_cell`: the test will use the previously generated list to test a series of cells using the function.
* `print_list_cell`: the test prints a universe to the console, the user has to verify that the printing is correct.

### List loader structure

test-list-loader.c

* `list_conway_load`: the test will attempt to load the universe from `data/glider.txt` and will check that the parameters of the returned structure are correct.

### List universe simulator

test-list-conway.c

* `list_count_neighbor`: the test will load the universe from `data/glider.txt` and checks several neighbor counts with and without considering the universe as a torus.
* `list_step`: the test will use the `data/archive-test` directory that contains 512 source textfiles and their next step solution. \n
  It will load each universe from its corresponding file, use the `list_step` function and compare the return's cell table with the given exact solution.

### List universe PBM image generator

test-list-generate-image.c

* `list_pgm_generate`: the test will load `data/glider.txt` universe and generate the associated image.
