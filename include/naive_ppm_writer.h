/**
 * @file naive_ppm_writer.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for the naive implementation of Conway's game of life ppm image printer
 * @version 0.1
 * @date 2021-02-22
 *
 * Naive implementation of the Conway's game of life: \n
 * The universe's size if given and constant. \n
 * The universe state is recorded using a character list (string) following the convention `.` for dead and `o` for alive.
 *
 * __API__
 * - function `naive_generate_image` to generate an image corresponding to a universe, with a number as a filename, in the `out` folder
 * - function `naive_generate_image_filename` to generate an image of given filename corresponding to a universe
 */

#include <stdio.h>
#include "naive_universe.h"


#ifndef CONWAY_NAIVE_WRITER
#define CONWAY_NAIVE_WRITER


/**
 * @brief Generate the image corresponding to a universe. \n
 * Image will be of PPM format and created in the `out` folder, with the filename `num.ppm`
 *
 * @param universe
 * @param num image number, for its filename
 */
void naive_generate_image(universe universe, int num);

/**
 * @brief Generate the image corresponding to a universe. \n
 * Image will be of PPM format.
 *
 * @param universe
 * @param filename
 */
void naive_generate_image_filename(universe universe, char *filename);


#endif
