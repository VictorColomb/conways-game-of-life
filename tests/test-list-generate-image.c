/**
 * @file test-list-generate-image.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executble source code for a linked list implementation of Conway's game of life image printer
 * @date 2021-03-18
 *
 * This test will load `data/glider.txt` and attemp to print the pgm image corresponding to the loaded universe
 */

#include <stdio.h>
#include <stdlib.h>

#include "list_universe.h"
#include "list_loader.h"
#include "list_pbm_writer.h"

int main(void)
{
  printf("* Starting linked list universe image printer...\n  | printing glider image...");

  universe u = list_conway_load("data/glider.txt");
  list_generate_image_filename(u, "out/test.pgm");

  printf(" OK!\n  | See out/test.pgm to check the output image.\n  +-> OK!\n");

  linked_list_free(u.cells);
  return 0;
}
