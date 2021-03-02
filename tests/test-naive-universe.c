/**
 * @file test-naive-universe.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executable source code for a naive implementation of Conway's game of life universe structure.
 * @date 2021-02-24
 *
 * Contains the following tests:
 * - test for the `naive_universe_get_cell` function
 * - test for the `naive_universe_print` function
 * - test for the `naive_universe_update_cell` function
 *
 * These functions are implemented in the naive_universe.h and naive_universe.c source files.
 *
 * The further-defined string constants are used by the different tests.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "naive_universe.h"

// Example 3x5 universes
char CELLS0[] = ".0.....0..000..";
char CELLS1[] = "...............";
char *CELLS1_check = "..............."; // immutable copy of CELLS1
char CELLS2[] = ".......0......."; // 0 at 1,2
char *CELLS2_check = ".......0.......";

universe u;

/**
 * @brief Test of the `naive_universe_get_cell` function
 */
void test_getcell()
{
  printf("  | testing naive_universe_get_cell...");

  assert(naive_universe_get_cell(u, 0, 0) == '.');
  assert(naive_universe_get_cell(u, 0, 1) == '0');
  assert(naive_universe_get_cell(u, 1, 2) == '0');

  printf(" OK!\n");
}

/**
 * @brief Test of the `naive_universe_print` function
 */
void test_print()
{
  printf("  | testing naive_universe_print...\n");

  print_naive_universe(u);

  printf("  |                                 OK!\n");
}

/**
 * @brief Test of the `naive_universe_update_cell` function
 */
void test_universeupdatecell()
{
  printf("  | testing naive_universe_update_cell...");

  naive_universe_update_cell(u, 1, 2, '0');
  assert(!strcmp(u.cells, CELLS2_check));

  printf(" OK!\n");
}

int main(void)
{
  printf("* Starting naive universe structure tests...\n");

  u.width = 5;
  u.height = 3;
  u.step_nb = 100;
  u.cells = CELLS0;

  test_getcell();
  test_print();

  printf("  | resetting universe...");
  u.cells = CELLS1;
  printf(" OK!\n");

  test_universeupdatecell();

  printf("  +-> OK!\n");

  return 0;
}
