/**
 * @file test-naive-generate-image.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executble source code for a naive implementation of Conway's game of life image printer
 * @date 2021-03-05
 *
 * This test will load `data/glider.txt` and attemp to print the pgm image corresponding to the 
 */

#include <stdio.h>
#include <stdlib.h>

#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_pbm_writer.h"

int main(void)
{
  printf("* Starting naive universe image printer...\n  | printing glider image...");

  universe u = naive_conway_load("data/glider.txt");
  naive_generate_image_filename(u, "out/test.pgm");

  printf(" OK!\n  | See out/test.pgm to check the output image.\n  +-> OK!\n");

  free(u.cells);
  return 0;
}
