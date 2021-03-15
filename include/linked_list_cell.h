/**
 * @file linked_list_cell.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a linked list implementation
 * @date 2021-03-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef CONWAY_LINKED_LIST
#define CONWAY_LINKED_LIST

typedef struct linked_cell linked_cell;
typedef linked_cell *linked_list;

struct linked_cell
{
  int row;
  int column;
  linked_list next;
};

/**
 * @brief Get a cell from a linked list by its index
 *
 * @param list
 * @param idx
 *
 * @pre `idx` has to be inferior to the number of cells in the list
 *
 * @return linked_cell of the given index
 */
linked_cell linked_list_get(linked_list list, int idx);

/**
 * @brief Insert an element into a linked list, sorted by row and column
 *
 * @param p_list pointer to a linked list
 * @param row
 * @param column
 */
void linked_list_insert(linked_list *p_list, int row, int column);

/**
 * @brief Delete an element from a linked list
 *
 * @param p_list pointer to a linked list
 * @param idx
 *
 * @pre `idx` has to be inferior to the number of cells in the list
 */
void linked_list_delete(linked_list *p_list, int idx);

/**
 * @brief Free a linked list from memory
 *
 * @param list
 */
void linked_list_free(linked_list list);

#endif
