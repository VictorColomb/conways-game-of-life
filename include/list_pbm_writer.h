/**
 * @file list_pbm_writer.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for a linked list implementation of Conway's game of life pbm image printer
 * @date 2021-03-18
 *
 * Naive implementation of the Conway's game of life: \n
 * The universe's size if given and constant. \n
 * The universe state is recorded using a character list (string) following the convention `.` for dead and `o` for alive.
 *
 * __API__
 * - function `list_generate_image` to generate an image corresponding to a universe, with a number as a filename, in the `out` folder
 * - function `list_generate_image_filename` to generate an image of given filename corresponding to a universe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_universe.h"

#ifndef CONWAY_LIST_WRITER
#define CONWAY_LIST_WRITER

/**
 * @brief Generate the image corresponding to a universe. \n
 * Image will be of PPM format and created in the `out` folder, with the filename `idx-XXX.ppm` where XXX in the the image index.
 *
 * @param u universe
 * @param idx image index, used for its filename
 */
void list_generate_image(universe u, int idx);

/**
 * @brief Generate the image corresponding to a universe. \n
 * Image will be of PPM format.
 *
 * @param u universe
 * @param filename
 */
void list_generate_image_filename(universe u, char *filename);

#endif
