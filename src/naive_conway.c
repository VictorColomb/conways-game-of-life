/**
 * @file naive_conway.c
 * @author Victor Colomb (vic.col@hotmaail.fr)
 * @brief Source file for a naive implementation of Conway's game of life simulator
 * @date 2021-03-01
*/

#include "naive_conway.h"

int naive_count_neighbors(universe u, int row, int column, bool consider_torus)
{
  int nb_neighbors = 0;

  int idx_row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int idx_col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int k = 0; k < 8; ++k)
  {
    int row_k = row + idx_row[k];
    int col_k = column + idx_col[k];

    if (consider_torus)
    {
      row_k = (row_k + u.height) % u.height;
      col_k = (col_k + u.width) % u.width;
    }

    if (consider_torus || (row_k >= 0 && row_k < u.height && col_k >= 0 && col_k < u.width))
    {
      if (naive_universe_get_cell(u, row_k, col_k) == 'o')
      {
        ++nb_neighbors;
      }
    }
  }

  return nb_neighbors;
}

universe naive_step(universe u, bool consider_torus)
{
  // copy universe cells
  char *new_cells = malloc((u.width * u.height + 1) * sizeof(char));
  new_cells[u.width * u.height] = '\0';
  strcpy(new_cells, u.cells);
  universe new_u = {u.width, u.height, u.step_nb - 1, new_cells};

  // go through every cell in the universe and apply game rules
  for (int row = 0; row < u.height; ++row)
  {
    for (int col = 0; col < u.width; ++col)
    {
      int nb_neighbors = naive_count_neighbors(u, row, col, consider_torus);
      char current_cell = naive_universe_get_cell(u, row, col);

      if (current_cell == '.')
      {
        if (nb_neighbors == 3)
        {
          naive_universe_update_cell(new_u, row, col, 'o');
        }
      }

      else
      {
        if (nb_neighbors < 2 || nb_neighbors > 3)
        {
          naive_universe_update_cell(new_u, row, col, '.');
        }
      }
    }
  }

  return new_u;
}

universe naive_simulation(universe u, bool print_to_console, bool generate_images, bool consider_torus)
{
  if (u.step_nb <= 0)
  {
    printf("The given universe has no steps to execute...\n");
    return u;
  }

  if (print_to_console)
  {
    printf("Initial state of the universe:\n==============================\n");
    print_naive_universe(u);
    printf("\n");
  }

  int step_nb = 0;
  while (u.step_nb > 1)
  {
    u = naive_step(u, consider_torus);

    if (print_to_console)
    {
      printf("State %2d of the universe:\n=========================\n", ++step_nb);
      print_naive_universe(u);
      printf("\n");
    }
  }

  u = naive_step(u, consider_torus);
  if (print_to_console)
  {
    printf("Final state of the universe:\n============================\n");
    print_naive_universe(u);
  }

  return u;
}
