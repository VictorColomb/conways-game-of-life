/**
 * @file test-naive-loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executable source code for a naive implementation of Conway's game of life loader.
 * @date 2021-02-25
 *
 * The test loads the `glider.txt` file from the `data` directory using the `naive-universe-load` function from naive_loader.c and checks it against a hardcoded version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "naive_universe.h"
#include "naive_loader.h"

char *FILENAME = "./data/glider.txt";
char *GLIDER_CELLS = ".o....................o.................ooo........................................................................................................................................................................................................................................................................................................................................................................................o";

int main(void)
{
  printf("* Starting naive universe loader tests...\n  | testing naive_conway_load... ");

  universe u = naive_conway_load(FILENAME);

  assert(u.width == 20);
  assert(u.height == 21);
  assert(u.step_nb == 10);

  assert(!strcmp(GLIDER_CELLS, u.cells));

  printf("OK!\n  +-> OK!\n");
  free(u.cells);

  return 0;
}
