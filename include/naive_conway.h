/**
 * @file naive_conway.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for the naive implementation of Conway's game of life stepper
 * @version 0.1
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

#include <stdbool.h>
#include "naive_universe.h"


#ifndef CONWAY_NAIVE
#define CONWAT_NAIVE


/**
 * @brief Get a naive universe's next iteration. \n
 * Decrements the universe's `step_nb` parameter by one.
 *
 * @param universe
 *
 * @return the given universe's next iteration
 */
universe naive_step(universe universe);

/**
 * @brief Get the final state of a universe, according to its `step_nb` parameter.
 *
 * @param universe
 * @param print_to_console *true* to print each step to the console
 * @param generate_images *true* to generate images
 *
 * @return the universe's final state
 */
universe naive_simulation(universe universe, bool print_to_console, bool generate_images);


#endif
