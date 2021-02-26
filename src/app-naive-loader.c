/**
 * @file app-naive-loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an executable that reads a universe structure from a source text file and prints it to the console.
 * @date 2021-02-26
 */

#include <stdio.h>
#include <stdlib.h>
#include "naive_universe.h"
#include "naive_loader.h"

int main(int argc, char **argv)
{
  // Assert enough arguments
  if (argc < 2)
  {
    printf("[!] You did not specify an inuput text file!\n\nUSAGE: ./app-naive-loader source_filename\n    > source_filename: path to a source text file for a universe structure\n");
    exit(EXIT_FAILURE);
  }

  prettyprint_naive_universe(naive_conway_load(argv[1]));
  return 0;
}
