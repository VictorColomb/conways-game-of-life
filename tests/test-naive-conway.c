/**
 * @file test-naive-conway.c
 * @author Victor Colomb
 * @brief Test executable source code for a naive implementation of Conway's game of life universe stepper
 * @date 2021-03-01
 *
 * Contains the following tests:
 * - test of the `naive_count_neighbors` function, using `data/glider.txt`
 * - test of the `naive_step` function, using source files from the `data/archive-test` directory
 * - test of the `naive_simulation` function, using `data/glider.txt` and checking a 10 step simulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_conway.h"

universe u;
char *GLIDER_10STEPS = "................................................................o.................o.o..................oo...........................................................................................................................................................................................................................................................................................................................";

/**
 * @brief Test of the `naive_count_neighbors` function
 *
 * This tests uses the `data/glider.txt` source file and checks 4 neighbors counts, including two with edge positions.
 */
    void
    test_count_neighbors()
{
  printf("  | testing naive_count_neighbors...");

  assert(naive_count_neighbors(u, 2, 2) == 2);
  assert(naive_count_neighbors(u, 5, 5) == 0);
  assert(naive_count_neighbors(u, 0, 0) == 1);
  assert(naive_count_neighbors(u, 20, 19) == 0);

  free(u.cells);
  printf(" OK!\n");
}

/**
 * @brief Test of the `naive_step` function
 *
 * This test uses the `data/archive-test` directory that contains 512 source files and their next step solution. \n
 * It will load each universe from each file, use the `naive_step` function and compare the return's cell table with the given exact solution.
 */
void test_naive_step()
{
  printf("  | testing naive_step...");

  for (int file_idx = 0; file_idx < 512; ++file_idx)
  {
    char filename[33];
    sprintf(filename, "./data/archive-test/test-%03d.txt", file_idx);
    universe u = naive_conway_load(filename);

    char sol_filename[37];
    sprintf(sol_filename, "./data/archive-test/test-%03d-sol.txt", file_idx);
    universe sol_u = naive_conway_load(sol_filename);

    universe perso_sol_u = naive_step(u);

    if (strcmp(perso_sol_u.cells, sol_u.cells))
    {
      printf("Problem with file %d:\n\nPersonal solution:\n==================\n", file_idx);
      print_naive_universe(perso_sol_u);
      printf("\nActual solution:\n================\n");
      print_naive_universe(sol_u);
    }

    assert(!strcmp(perso_sol_u.cells, sol_u.cells));

    free(u.cells);
    free(sol_u.cells);
    free(perso_sol_u.cells);
  }

  printf(" OK!\n");
}

/**
 * @brief Test of the `naive_simulation` function
 *
 * This test uses the `data/glider.txt` source files, launches a 10 step simulation and compares the result with the exact solution given by the `GLIDER_10STEPS` constant.
 */
void test_naive_simulation()
{
  printf("  | testing naive_universe function...");

  u = naive_conway_load("./data/glider.txt");
  universe final_u = naive_simulation(u, false, false);

  assert(final_u.step_nb == 0);
  assert(!strcmp(final_u.cells, GLIDER_10STEPS));

  free(u.cells);
  free(final_u.cells);
  printf(" OK!\n");
}

int main(void)
{
  printf("* Starting naive universe stepper tests...\n");
  u = naive_conway_load("./data/glider.txt");

  test_count_neighbors();
  test_naive_step();
  test_naive_simulation();

  printf("  +-> OK!\n");
  return 0;
}
