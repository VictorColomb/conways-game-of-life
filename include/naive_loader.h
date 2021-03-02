/**
 * @file naive_loader.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for the naive implementation of Conway's game of life loader.
 * @date 2021-02-22
 *
 * Naive implementation of the Conway's game of life: \n
 * The universe's size if given and constant. \n
 * The universe state is recorded using a character list (string) following the convention `.` for dead and `o` for alive.
 *
 * The loader takes a text file following the format:
 * - Line 1: {width} {height}
 * - Line 2: {number of steps}
 * - The following lines contain the initial state of the universe, according to the aforemontionned convention.
 *
 * __API__
 * - function `naive_conway_load` to build a `universe` structure from a text file
 */

#include <stdio.h>
#include <stdlib.h>

#include "naive_universe.h"

#ifndef CONWAY_NAIVE_LOADER
#define CONWAY_NAIVE_LOADER

/**
 * @brief Parse a text file into a universe structure.
 *
 * @param data_filename source text file filename
 * @return the corresponding universe structure
 */
universe naive_conway_load(char *data_filename);

#endif
