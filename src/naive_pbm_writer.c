/**
 * @file naive_pbm_writer.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a naive implementation of Conway's game of life ppm image printer
 * @date 2021-03-05
 */

#include "naive_pbm_writer.h"

void naive_generate_image(universe u, int idx)
{
  char filename[18];
  sprintf(filename, "out/img-%03d.pgm", idx);

  naive_generate_image_filename(u, filename);
}

void naive_generate_image_filename(universe u, char *filename)
{
  FILE *p_file = NULL;
  p_file = fopen(filename, "w");

  if (p_file == NULL)
  {
    fprintf(stderr, "[!] Cannot write to file.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(p_file, "P1\n%d %d\n", u.width, u.height);

  int length = u.width * u.height;
  for (int i = 0; i < length; ++i)
  {
    fprintf(p_file, "%c", u.cells[i] == '.' ? '0' : '1');
  }
  fprintf(p_file, "\n");

  fclose(p_file);
  p_file = NULL;
}
