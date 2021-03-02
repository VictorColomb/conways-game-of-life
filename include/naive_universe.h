/**
 * @file naive_universe.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a naive implementation of Conway's game of life universe structure
 * @date 2021-02-17
 *
 * Naive implementation of the Conway's game of life: \n
 * The universe's size if given and constant. \n
 * The universe state is recorded using a character list (string) following the convention `.` for dead and `o` for alive.
 *
 * __API__
 * - structure `struct universe` recording height, width, number of steps and cell list of a universe
 * - type `universe` referring to the `struct universe` structure
 * - function `naive_universe_get_cell` cell getter
 * - function `naive_universe_update_cell` cell setter, modifies the given universe
 * - function `print_naive_universe` to print a universe to the console
 * - function `prettyprint_naive_universe` to pretty-print a universe to the console
 */

#ifndef CONWAY_NAIVE_UNIVERSE
#define CONWAY_NAIVE_UNIVERSE

#include <stdio.h>
#include <string.h>

typedef struct universe universe;

/**
 * @brief Structure representing a universe: width, height, number of simulation steps and current cells state.
 *
 * Structure represented by the `universe` type.
 */
struct universe
{
  int width;
  int height;
  int step_nb;
  char *cells;
};

/**
 * @brief Get a cell from a universe.
 *
 * @param u universe
 * @param row
 * @param column
 *
 * @pre `row` and `column` should be inferior respectively to the height and width of the universe.
 *
 * @return `.` if the cell is dead and `0` if it is alive
 */
char naive_universe_get_cell(universe u, int row, int column);

/**
 * @brief Update a given cell from a universe to a given state.
 *
 * @param u universe
 * @param row
 * @param column
 * @param state *true* for alive, *false* for dead
 */
void naive_universe_update_cell(universe u, int row, int column, char state);

/**
 * @brief Print a universe to the console, formatted as follows:
 *
 * ```
 * {width} {height}
 * {number of steps}
 * Array of cells, . representing a dead cell and 0 a live one.
 * ```
 *
 * @param u universe
 */
void print_naive_universe(universe u);

/**
 * @brief Pretty-prints a universe to the console, formatted as follows:
 *
 * ```
 * Universe width:  {width}
 * Universe height: {height}
 * Number of steps: {number of steps}
 * Universe cells state:
 * =====================
 * {universe cells}
 * ```
 *
 * @param u universe
 */
void prettyprint_naive_universe(universe u);

#endif
