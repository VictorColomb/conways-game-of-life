/**
 * @file list_loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source file for a naive implementation of Conway's game of life loader.
 * @date 2021-03-13
 */

#include "list_loader.h"

universe list_conway_load(char *filename)
{
  FILE *p_file;
  p_file = fopen(filename, "r");

  int width;
  int height;
  int nb_step;

  fscanf(p_file, "%d %d", &width, &height);
  fscanf(p_file, "%d\n", &nb_step);

  linked_list cells = NULL;
  linked_list current_cell = cells;
  char buffer[width + 2];

  for (int i = 0; i < height; ++i)
  {
    fgets(buffer, width + 2, p_file);

    for (int j = 0; j < width; ++j)
    {
      if (buffer[j] == 'o')
      {
        if (cells == NULL)
        {
          cells = malloc(sizeof(linked_cell));
          cells->row = i;
          cells->column = j;
          cells->next = NULL;

          current_cell = cells;
        }
        else
        {
          linked_list new_cell = malloc(sizeof(linked_cell));
          new_cell->row = i;
          new_cell->column = j;
          new_cell->next = NULL;

          current_cell->next = new_cell;
          current_cell = new_cell;
        }
      }
    }
  }
  fclose(p_file);

  universe u = {width, height, nb_step, cells};
  return u;
}
