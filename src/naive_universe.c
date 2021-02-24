/**
 * @file naive_universe.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source file for a naive implementation of Conway's game of life universe structure
 * @date 2021-02-23
 */

#include <stdio.h>
#include "naive_universe.h"

char naive_universe_get_cell(universe u, int row, int column)
{
  return u.cells[row * u.width + column];
}

universe naive_universe_set_cell(universe u, int row, int column, char state)
{
  *(u.cells + row * u.width + column) = state;
  return u;
}

void naive_universe_update_cell(universe *p_u, int row, int column, char state)
{
  p_u->cells[row * p_u->width + column] = state;
}

void naive_universe_print(universe u)
{
  printf("%d %d\n%d\n", u.width, u.height, u.step_nb);
  for(int row = 0; row < u.height; ++row)
  {
    printf("%.*s\n", u.width, u.cells + row * u.width);
  }
}
