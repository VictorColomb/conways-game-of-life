/**
 * @file list_conway_expandable.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for an expandable linked list implementation of Conway's game of life simulation
 * @date 2021-03-16
 */

#include <stdbool.h>

#include "list_universe.h"
#include "list_pbm_writer.h"

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
linked_list list_neighbors_expandable(universe u, int row, int column);

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
int list_count_neighbors_expandable(universe u, int row, int column);

/**
 * @brief Recenter a universe (move to all positive, increase height and width if needed)
 *
 * @param u universe
 * @return recentered universe
 */
universe recenter_universe(universe u);

/**
 * @brief Get a naive universe's next iteration. \n
 * Decrements the universe's `step_nb` parameter by one.
 *
 * @param u universe
 * @param consider_torus *true* to consider the universe as a torus
 *
 * @return the given universe's next iteration
 */
universe list_step_expandable(universe u);

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
universe list_simulation_expandable(universe u, bool print_to_console, bool generate_images);
