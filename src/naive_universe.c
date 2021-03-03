/**
 * @file naive_universe.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source file for a naive implementation of Conway's game of life universe structure
 * @date 2021-02-23
 */

#include "naive_universe.h"

char naive_universe_get_cell(universe u, int row, int column)
{
  return u.cells[row * u.width + column];
}

void naive_universe_update_cell(universe u, int row, int column, char state)
{
  u.cells[row * u.width + column] = state;
}

void print_naive_cells(universe u)
{
  for (int row = 0; row < u.height; ++row)
  {
    printf("%.*s\n", u.width, u.cells + row * u.width);
  }
}

void print_naive_universe(universe u)
{
  printf("%d %d\n%d\n", u.width, u.height, u.step_nb);
  print_naive_cells(u);
}

void prettyprint_naive_universe(universe u)
{
  printf("Universe width:  %d\nUniverse height: %d\nNumber of steps: %d\n\nUniverse cells state:\n=====================\n\n", u.width, u.height, u.step_nb);
  print_naive_cells(u);
}
