/**
 * @file test-list-conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executable source code for a linked list implementation of Conway's game of life universe simulator
 * @date 2021-03-16
 */

#include <assert.h>

#include "list_conway.h"
#include "list_loader.h"

char *filename = "data/glider.txt";

/**
 * @brief Test of the `list_count_neighbors` function
 *
 * This tests uses the `data/glider.txt` source file and checks several neighbor counts.
 */
void test_list_countneighbors()
{
  printf("  | testing list_count_neighbors...");
  universe u = list_conway_load(filename);

  assert(list_count_neighbors(u, 0, 0, false) == 1);
  assert(list_count_neighbors(u, 1, 1, false) == 5);
  assert(list_count_neighbors(u, 10, 10, false) == 0);

  printf(" OK!\n  | testing list_count_neighbors while considering the universe as a torus...");

  assert(list_count_neighbors(u, 0, 0, true) == 2);
  assert(list_count_neighbors(u, 1, 1, true) == 5);
  assert(list_count_neighbors(u, 10, 10, true) == 0);

  printf(" OK!\n");
  linked_list_free(u.cells);
}

/**
 * @brief Determine whether two linked lists are identical, comparing all cells
 *
 * @param a first linked list
 * @param b second linked list
 * @return *true* if the lists are identical, *false* otherwise
 */
bool compare_linked_lists(linked_list a, linked_list b)
{
  while (a != NULL && b != NULL)
  {
    if (a->row != b->row || a->column != b->column)
      return false;

    a = a->next;
    b = b->next;
  }

  if (a != NULL || b != NULL)
    return false;

  return true;
}

/**
 * @brief Test of the `list_step` function
 *
 * This test uses the `data/archive-test` directory that contains 512 source files and their next step solution. \n
 * It will load each universe from each file, use the `list_step` function and compare the return's cell table with the given exact solution.
 */
void test_list_step()
{
  printf("  | testing list_step...");

  for (int file_idx = 0; file_idx < 512; ++file_idx)
  {
    char filename[33];
    sprintf(filename, "./data/archive-test/test-%03d.txt", file_idx);
    universe u = list_conway_load(filename);

    char sol_filename[38];
    sprintf(sol_filename, "./data/archive-test/test-%03d-sol.txt", file_idx);
    universe sol_u = list_conway_load(sol_filename);

    u = list_step(u, false);
    assert(compare_linked_lists(u.cells, sol_u.cells));

    linked_list_free(u.cells);
    linked_list_free(sol_u.cells);
  }

  printf(" OK!\n");
}

int main(void)
{
  printf("* Starting linked list universe stepper tests...\n");

  test_list_countneighbors();
  test_list_step();

  printf("  +-> OK!\n");
  return 0;
}
