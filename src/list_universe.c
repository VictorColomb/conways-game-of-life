/**
 * @file list_universe.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a naive implementation of Conway's game of life universe structure
 * @date 2021-03-09
 */

#include "list_universe.h"

bool list_universe_get_cell(universe u, int row, int column)
{
  linked_list current_cell = u.cells;

  while (current_cell != NULL)
  {
    if (current_cell->row == row && current_cell->column == column)
    {
      return true;
    }

    current_cell = current_cell->next;
  }

  return false;
}

void print_list_cells(universe u)
{
  linked_list current_cell = u.cells;
  int row = 0;
  int column = 0;

  while (current_cell != NULL)
  {
    // print full lines between current position and next cell position
    for (; row < current_cell->row; ++row)
    {
      for (; column < u.width; ++column)
      {
        printf(".");
      }
      column = 0;
      printf("\n");
    }

    // print beginning of next cell line
    for (; column < current_cell->column; ++column)
    {
      printf(".");
    }

    printf("o");

    // increment current position
    if (++column == u.width)
    {
      ++row;
      column = 0;
      printf("\n");
    }

    current_cell = current_cell->next;
  }

  // print remaining dead cells
  for (; row < u.height; ++row)
  {
    for (; column < u.width; ++column)
    {
      printf(".");
    }
    column = 0;
    printf("\n");
  }
}

void print_list_universe(universe u)
{
  printf("%d %d\n%d\n", u.width, u.height, u.step_nb);
  print_list_cells(u);
}

void prettyprint_list_universe(universe u)
{
  printf("Universe width:  %d\nUniverse height: %d\nNumber of steps: %d\n\nUniverse cells state:\n=====================\n\n", u.width, u.height, u.step_nb);
  print_list_cells(u);
}
