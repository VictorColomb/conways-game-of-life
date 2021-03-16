/**
 * @file linked_list_cell.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for a linked list implementation
 * @date 2021-03-06
 */

#include "linked_list_cell.h"

linked_cell linked_list_get(linked_list list, int idx)
{
  for (int i = 0; i < idx; ++i)
  {
    list = list->next;

    if (list == NULL)
    {
      fprintf(stderr, "[!] Linked list get failed, index out of bounds.\n");
      exit(EXIT_FAILURE);
    }
  }

  return *list;
}

bool linked_cell_smaller(linked_list cell1, linked_list cell2)
{
  return (cell1->row < cell2->row) || (cell1->row == cell2->row && cell1->column <= cell2->column);
}

void linked_list_insert_unsorted(linked_list *p_list, int row, int column)
{
  linked_list new_cell = malloc(sizeof(linked_cell));
  new_cell->row = row;
  new_cell->column = column;
  new_cell->next = *p_list;

  *p_list = new_cell;
}

void linked_list_insert(linked_list *p_list, int row, int column)
{
  // if list empty, create a single cell one
  if (*p_list == NULL)
  {
    linked_list new_cell = malloc(sizeof(linked_cell));
    new_cell->row = row;
    new_cell->column = column;
    new_cell->next = NULL;

    *p_list = new_cell;
    return;
  }

  linked_list current_cell = *p_list;
  linked_list previous_cell = *p_list;
  int loop_idx = 0;

  linked_list new_cell = malloc(sizeof(linked_cell));
  new_cell->row = row;
  new_cell->column = column;

  while (linked_cell_smaller(current_cell, new_cell))
  {
    if (current_cell->next == NULL)
    {
      if (current_cell->row == row && current_cell->column == column)
      {
        free(new_cell);
        return;
      }

      new_cell->next = NULL;
      current_cell->next = new_cell;
      return;
    }

    previous_cell = current_cell;
    current_cell = current_cell->next;

    ++loop_idx;
  }

  // if the cell to insert is already in the list
  if (previous_cell->row == row && previous_cell->column == column)
  {
    free(new_cell);
    return;
  }

  // if the cell to insert is in first position
  if (!loop_idx)
  {
    new_cell->next = *p_list;
    *p_list = new_cell;

    return;
  }

  new_cell->next = current_cell;
  previous_cell->next = new_cell;
}

void linked_list_delete(linked_list *p_list, int row, int column)
{
  // if list empty
  if (*p_list == NULL)
    return;

  // if the first cell is to be deleted
  if ((*p_list)->row == row && (*p_list)->column == column)
  {
    linked_list delete = *p_list;
    *p_list = delete->next;

    free(delete);
    return;
  }

  linked_list current_cell = *p_list;
  linked_list previous_cell = NULL;

  while (current_cell->row != row || current_cell->column != column)
  {
    previous_cell = current_cell;
    current_cell = current_cell->next;

    if (current_cell == NULL)
      return;
  }

  previous_cell->next = current_cell->next;
  free(current_cell);
}

void linked_list_free(linked_list list)
{
  if (list == NULL)
    return;

  linked_list next_list = list->next;
  free(list);

  while (next_list != NULL)
  {
    list = next_list;
    next_list = next_list->next;

    free(list);
  }
}
