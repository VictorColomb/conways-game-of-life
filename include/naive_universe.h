/**
 * @file naive_universe.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a naive implementation of Conway's game of life universe structure
 * @version 0.1
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
 * - function`naive_universe_set_cell` cell setter, returns a new universe
 * - function `naive_universe_update_cell` cell setter, modifies the given universe
 */

#include <stdbool.h>


#ifndef CONWAY_NAIVE_UNIVERSE
#define CONWAY_NAIVE_UNIVERSE


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
 * @param uni universe
 * @param row
 * @param column
 *
 * @pre `row` and `column` should be inferior respectively to the height and width of the universe.
 *
 * @return *true* if the cell is alive, *false* if it's dead
 */
bool naive_universe_get_cell(universe uni, int row, int column);

/**
 * @brief Create a copy of a universe with a changed cell.
 *
 * @param uni universe
 * @param row
 * @param column
 * @param state *true* for alive or *false* for dead
 * @return the same universe except for the given cell
 */
universe naive_universe_set_cell(universe uni, int row, int column, bool state);

/**
 * @brief Update a given cell from a universe to a given state.
 *
 * @param p_uni pointer to the universe
 * @param row
 * @param column
 * @param state *true* for alive, *false* for dead
 */
void naive_universe_update_cell(universe *p_uni, int row, int column, bool state);


#endif
