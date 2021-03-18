/**
 * @file list_pbm_writer.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a linked list implementation of Conway's game of life ppm image printer
 * @date 2021-03-18
 */

#include "list_pbm_writer.h"

void list_generate_image(universe u, int idx)
{
  char filename[18];
  sprintf(filename, "out/img-%03d.pgm", idx);

  list_generate_image_filename(u, filename);
}

void list_generate_image_filename(universe u, char *filename)
{
  FILE *p_file = NULL;
  p_file = fopen(filename, "w");

  if (p_file == NULL)
  {
    fprintf(stderr, "[!] Cannot write to file.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(p_file, "P1\n%d %d\n", u.width, u.height);

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
        fprintf(p_file, "0");
      }
      column = 0;
    }

    // print beginning of next cell line
    for (; column < current_cell->column; ++column)
      fprintf(p_file, "0");

    fprintf(p_file, "1");

    // increment current position
    if (++column == u.width)
    {
      ++row;
      column = 0;
    }

    current_cell = current_cell->next;
  }

  // print remaining dead cells
  for (; row < u.height; ++row)
  {
    for (; column < u.width; ++column)
    {
      fprintf(p_file, "0");
    }
    column = 0;
  }

  fprintf(p_file, "\n");
  fclose(p_file);
  p_file = NULL;
}
