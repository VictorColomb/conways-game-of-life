/**
 * @file naive_conway.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a naive implementation of Conway's game of life simulation
 * @date 2021-02-22
 *
 * Naive implementation of the Conway's game of life: \n
 * The universe's size if given and constant. \n
 * The universe state is recorded using a character list (string) following the convention `.` for dead and `o` for alive.
 *
 * Stepper works the following way:
 * - *NULL*
 *
 * __API__
 * - function `naive_step` to get a universe's next step
 * - function `naive_simulation` to get a universe's final step and optionally print to console and generate images
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naive_universe.h"
#include "naive_pbm_writer.h"

#ifndef CONWAY_NAIVE
#define CONWAY_NAIVE

/**
 * @brief Count alive neighbors of a cell in a given universe.
 *
 * @param u universe
 * @param row
 * @param column
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return number of alive neighbors of the given cell
 */
int naive_count_neighbors(universe u, int row, int column, bool consider_torus);

/**
 * @brief Get a naive universe's next iteration. \n
 * Decrements the universe's `step_nb` parameter by one.
 *
 * @param u universe
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return the given universe's next iteration
 */
universe naive_step(universe u, bool consider_torus);

/**
 * @brief Get the final state of a universe, according to its `step_nb` parameter.
 *
 * @param u universe
 * @param print_to_console *true* to print each step to the console
 * @param generate_images *true* to generate images
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return the universe's final state
 */
universe naive_simulation(universe u, bool print_to_console, bool generate_images, bool consider_torus);

#endif
