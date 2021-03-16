/**
 * @file list_conway.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a naive implementation of Conway's game of life simulation
 * @date 2021-03-15
 */

#include <stdbool.h>

#include "list_universe.h"

/**
 * @brief Get a list of a cell's neighbors in a universe
 *
 * @param u universe
 * @param row
 * @param column
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return linked_list of neighbors
 */
linked_list list_neighbors(universe u, int row, int column, bool consider_torus);

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
int list_count_neighbors(universe u, int row, int column, bool consider_torus);

/**
 * @brief Get a naive universe's next iteration. \n
 * Decrements the universe's `step_nb` parameter by one.
 *
 * @param u universe
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return the given universe's next iteration
 */
universe list_step(universe u, bool consider_torus);

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
universe list_simulation(universe u, bool print_to_console, bool generate_images, bool consider_torus);
