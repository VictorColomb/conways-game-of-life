# Tests Documentation {#tests}

We provide tests for all implemented functions. \n
Compile and launch all tests using `make launch-tests`.

## Tests for the naive implementation

### Naive universe structure

* `naive_universe_get_cell`: the test creates a universe from a string constant and checks that the function applied to three different cells returns the correct character.
* `naive_universe_print`: the test prints a universe to the console, the user has to verify that the printing is correct.
* `naive_update_cell`: the test updates a cell of a universe and verifies the new string.

### Naive loader

* `naive_conway_load`: the test will attempt to load the universe from `data/glider.txt` and will check that the parameters of the returned structure are correct.

### Naive universe simulator

* `naive_count_neighbor`: the test loads the universe from `data/glider.txt` and checks several neighbor counts with and without considering the universe as a torus.
* `naive_step`: the test uses the `data/archive-test` directory that contains 512 source textfiles and their next step solution. \n
  It will load each universe from its corresponding file, use the `naive_step` function and compare the return's cell table with the given exact solution.
