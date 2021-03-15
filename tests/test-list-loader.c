/**
 * @file test-naive-loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Test executable source code for a linked list implementation of Conway's game of life loader.
 * @date 2021-03-13
 *
 * The test loads the `glider.txt` file from the `data` directory using the `list-universe-load` function from list_loader.c and checks it against a hardcoded version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list_loader.h"

linked_list GLIDER = NULL;
char *glider_filename = "data/glider.txt";

int main(void)
{
  printf("* Starting list universe loader tests...\n  | testing list_conway_load... ");

  universe loaded_glider = list_conway_load(glider_filename);

  linked_list_insert(&GLIDER, 20, 19);
  linked_list_insert(&GLIDER, 2, 2);
  linked_list_insert(&GLIDER, 2, 1);
  linked_list_insert(&GLIDER, 2, 0);
  linked_list_insert(&GLIDER, 1, 2);
  linked_list_insert(&GLIDER, 0, 1);

  linked_list current_cell = GLIDER;
  linked_list glider_current_cell = loaded_glider.cells;

  assert(loaded_glider.width == 20);
  assert(loaded_glider.height == 21);
  assert(loaded_glider.step_nb == 10);

  while(current_cell != NULL)
  {
    assert(current_cell->column == glider_current_cell->column && current_cell->row == glider_current_cell->row);
    current_cell = current_cell->next;
    glider_current_cell = glider_current_cell->next;
  }
  assert(glider_current_cell == NULL);

  linked_list_free(loaded_glider.cells);
  linked_list_free(GLIDER);
  printf("OK!\n  +-> OK!\n");
}
