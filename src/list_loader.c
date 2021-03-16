/**
 * @file list_loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a naive implementation of Conway's game of life loader.
 * @date 2021-03-13
 */

#include "list_loader.h"

universe list_conway_load(char *filename)
{
  // open file
  FILE *p_file;
  p_file = fopen(filename, "r");

  int width;
  int height;
  int nb_step;

  // get width, height and number of steps
  int fscanf_result = fscanf(p_file, "%d %d", &width, &height);
  fscanf_result += fscanf(p_file, "%d\n", &nb_step);

  if (fscanf_result != 3)
  {
    fprintf(stderr, "[!] File not properly formatted !\n");
    exit(EXIT_FAILURE);
  }

  linked_list cells = NULL;
  linked_list current_cell = cells;
  char buffer[width + 2];

  for (int i = 0; i < height; ++i)
  {
    // read and process one line from the file
    fgets(buffer, width + 2, p_file);

    for (int j = 0; j < width; ++j)
    {
      if (buffer[j] == 'o')
      {
        if (cells == NULL)
        // if the list is empty
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
