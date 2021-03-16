/**
 * @file list_universe.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a linked list implementation of Conway's game of life universe structure
 * @date 2021-03-09
 */

#include <stdio.h>
#include <stdbool.h>

#include "linked_list_cell.h"

#ifndef CONWAY_LIST_UNIVERSE
#define CONWAY_LIST_UNIVERSE

typedef struct universe universe;

struct universe
{
  int width;
  int height;
  int step_nb;
  linked_list cells;
};

/**
 * @brief Get a cell's state from a universe
 *
 * @param u universe
 * @param row
 * @param column
 */
bool list_universe_get_cell(universe u, int row, int column);

/**
 * @brief Print a universe's cells to the console
 *
 * @param u universe
 */
void print_list_cells(universe u);

/**
 * @brief Print a universe to the console.
 *
 * The universe is formatted as follows:
 *
 * ```
 * {width} {height}
 * {number of steps}
 * Array of cells, . representing a dead cell and 0 a live one.
 * ```
 *
 * @param u universe
 */
void print_list_universe(universe u);

/**
 * @brief Pretty-prints a universe to the console.
 *
 * The universe is formatted as follows:
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
void prettyprint_list_universe(universe u);

#endif
