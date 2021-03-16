/**
 * @file list_conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a linked list implementation of Conway's game of life simulator
 * @date 2021-03-15
 */

#include "list_conway.h"

linked_list list_neighbors(universe u, int row, int column, bool consider_torus)
{
  linked_list neighbors = NULL;
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
      linked_list_insert_unsorted(&neighbors, row_k, col_k);
  }

  return neighbors;
}

int list_count_neighbors(universe u, int row, int column, bool consider_torus)
{
  int nb_neighbors = 0;
  linked_list neighbors = list_neighbors(u, row, column, consider_torus);
  linked_list current_neighbor = neighbors;

  while (current_neighbor != NULL)
  {
    if (list_universe_get_cell(u, current_neighbor->row, current_neighbor->column))
      ++nb_neighbors;

    current_neighbor = current_neighbor->next;
  }

  linked_list_free(neighbors);
  return nb_neighbors;
}

universe list_step(universe u, bool consider_torus)
{
  linked_list current_cell = u.cells;
  linked_list newborn_cells = NULL;
  linked_list dying_cells = NULL;

  // for all living cells
  while (current_cell != NULL)
  {
    linked_list neighbors = list_neighbors(u, current_cell->row, current_cell->column, consider_torus);
    linked_list current_neighbor = neighbors;

    // go through dead neighbors and check if they become alive next cycle
    while (current_neighbor != NULL)
    {
      if (!list_universe_get_cell(u, current_neighbor->row, current_neighbor->column))
      {
        if (list_count_neighbors(u, current_neighbor->row, current_neighbor->column, consider_torus) == 3)
          linked_list_insert(&newborn_cells, current_neighbor->row, current_neighbor->column);
      }

      current_neighbor = current_neighbor->next;
    }

    // check if the cell dies
    int nb_neighbors = list_count_neighbors(u, current_cell->row, current_cell->column, consider_torus);
    if (nb_neighbors < 2 || nb_neighbors > 3)
      linked_list_insert(&dying_cells, current_cell->row, current_cell->column);

    current_cell = current_cell->next;

    linked_list_free(neighbors);
  }

  // delete dying cells
  linked_list current_dying_cell = dying_cells;
  while (current_dying_cell != NULL)
  {
    linked_list_delete(&u.cells, current_dying_cell->row, current_dying_cell->column);
    current_dying_cell = current_dying_cell->next;
  }
  linked_list_free(dying_cells);

  // add newborn cells
  linked_list current_born_cell = newborn_cells;
  while (current_born_cell != NULL)
  {
    linked_list_insert(&u.cells, current_born_cell->row, current_born_cell->column);
    current_born_cell = current_born_cell->next;
  }
  linked_list_free(newborn_cells);

  u.step_nb -= 1;
  return u;
}

universe list_simulation(universe u, bool print_to_console, bool generate_images, bool consider_torus)
{
  if (u.step_nb <= 0)
  {
    printf("The given universe has no steps to execute...\n");
    return u;
  }

  if (print_to_console)
  {
    printf("Initial state of the universe:\n==============================\n");
    print_list_cells(u);
    printf("\n");
  }
  /**
  if (generate_images)
  {
    naive_generate_image(u, 0);
  }
  */

  int step_nb = 0;
  while (u.step_nb > 1)
  {
    u = list_step(u, consider_torus);
    ++step_nb;

    if (print_to_console)
    {
      printf("State %2d of the universe:\n=========================\n", step_nb);
      print_list_cells(u);
      printf("\n");
    }
    /**
    if (generate_images)
    {
      naive_generate_image(u, step_nb);
    }
    */
  }

  u = list_step(u, consider_torus);
  if (print_to_console)
  {
    printf("Final state of the universe:\n============================\n");
    print_list_cells(u);
  }
  /**
  if (generate_images)
  {
    naive_generate_image(new_u, ++step_nb);
  }
  */

  return u;
}
