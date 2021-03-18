/**
 * @file list_conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an expandable linked list implementation of Conway's game of life simulator
 * @date 2021-03-15
 */

#include "list_conway_expandable.h"

linked_list list_neighbors_expandable(universe u, int row, int column)
{
  linked_list neighbors = NULL;
  int idx_row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int idx_col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int k = 0; k < 8; ++k)
  {
    int row_k = row + idx_row[k];
    int col_k = column + idx_col[k];

    linked_list_insert_unsorted(&neighbors, row_k, col_k);
  }

  return neighbors;
}

int list_count_neighbors_expandable(universe u, int row, int column)
{
  int nb_neighbors = 0;
  linked_list neighbors = list_neighbors_expandable(u, row, column);
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

universe recenter_universe(universe u)
{
  // find universe minimum cell (in the negatives)
  int min_row = 0;
  int min_column = 0;
  linked_list current_cell = u.cells;
  while (current_cell != NULL)
  {
    if (min_row > current_cell->row)
    {
      min_row = current_cell->row;
      u.height -= min_row;
    }
    if (min_column > current_cell->column)
    {
      min_column = current_cell->column;
      u.width -= min_column;
    }

    current_cell = current_cell->next;
  }

  // move universe back to origin
  current_cell = u.cells;
  while (current_cell != NULL)
  {
    current_cell->row -= min_row;
    current_cell->column -= min_column;

    current_cell = current_cell->next;
  }

  // find universe maximum
  current_cell = u.cells;
  int max_row = current_cell->row;
  int max_column = current_cell->column;
  current_cell = current_cell->next;
  while (current_cell != NULL)
  {
    if (max_row < current_cell->row)
      max_row = current_cell->row;
    if (max_column < current_cell->column)
      max_column = current_cell->column;

    current_cell = current_cell->next;
  }

  // resize universe if needed
  if (max_row >= u.height)
    u.height = max_row + 1;
  if (max_column >= u.width)
    u.width = max_column + 1;

  return u;
}

universe list_step_expandable(universe u)
{
  linked_list current_cell = u.cells;
  linked_list newborn_cells = NULL;
  linked_list dying_cells = NULL;

  // for all living cells
  while (current_cell != NULL)
  {
    linked_list neighbors = list_neighbors_expandable(u, current_cell->row, current_cell->column);
    linked_list current_neighbor = neighbors;

    // go through dead neighbors and check if they become alive next cycle
    while (current_neighbor != NULL)
    {
      if (!list_universe_get_cell(u, current_neighbor->row, current_neighbor->column))
      {
        if (list_count_neighbors_expandable(u, current_neighbor->row, current_neighbor->column) == 3)
          linked_list_insert(&newborn_cells, current_neighbor->row, current_neighbor->column);
      }

      current_neighbor = current_neighbor->next;
    }

    // check if the cell dies
    int nb_neighbors = list_count_neighbors_expandable(u, current_cell->row, current_cell->column);
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

  u = recenter_universe(u);
  return u;
}

universe list_simulation_expandable(universe u, bool print_to_console, bool generate_images)
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
  if (generate_images)
  {
    list_generate_image(u, 0);
  }

  int step_nb = 0;
  while (u.step_nb > 1)
  {
    u = list_step_expandable(u);
    ++step_nb;

    if (print_to_console)
    {
      printf("State %2d of the universe:\n=========================\n", step_nb);
      print_list_cells(u);
      printf("\n");
    }
    if (generate_images)
    {
      list_generate_image(u, step_nb);
    }
  }

  u = list_step_expandable(u);
  if (print_to_console)
  {
    printf("Final state of the universe:\n============================\n");
    print_list_cells(u);
  }
  if (generate_images)
  {
    list_generate_image(u, ++step_nb);
  }

  return u;
}
