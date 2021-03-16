/**
 * @file app-list-loader.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an executable that reads a universe structure from a source text file and prints it to the console.
 * @date 2021-03-16
 */

#include "list_loader.h"

int main(int argc, char **argv)
{
  // Assert enough arguments
  if (argc < 2)
  {
    printf("[!] You did not specify an inuput text file!\n\nUSAGE: ./app-naive-loader source_filename\n    > source_filename: path to a source text file for a universe structure\n");
    exit(EXIT_FAILURE);
  }

  universe u = list_conway_load(argv[1]);
  prettyprint_list_universe(u);

  linked_list_free(u.cells);
  return 0;
}
