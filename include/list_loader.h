/**
 * @file list_loader.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for the linked list implementation of Conway's game of life loader.
 * @date 2021-03-13
 */

#include <stdio.h>

#include "linked_list_cell.h"
#include "list_universe.h"

#ifndef CONWAY_LIST_LOADER
#define CONWAY_LIST_LOADER

/**
 * @brief Parse a text file into a universe structure.
 *
 * @param filename source text file filename
 *
 * @return the corresponding universe structure
 */
universe list_conway_load(char *filename);

#endif
