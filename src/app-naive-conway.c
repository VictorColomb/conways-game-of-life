/**
 * @file app-naive-conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an executable of a naive implementation of Conway's game of life
 * @date 2021-03-02
 *
 * __USAGE__ `./app-naive-conway [-ipt?] filename`
 * * `-?`: print source textfile formatting help
 * * `-p`: print simulation steps to console
 * * `-i`:  generate image output for each steps
 * * `-t`: consider the universe as a torus
 */

#include <stdio.h>

#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_conway.h"
#include "naive_optionsparser.h"

int main(int argc, char **argv)
{
  naive_options options = parse_options(argc, argv);
  if (options.print_formatting_help)
  {
    do_print_formatting_help();
  }

  universe u = naive_conway_load(options.filename);

  if (options.generate_images && u.step_nb > 1000)
  {
    free(u.cells);
    fprintf(stderr, "[!] Cannot generate image output for more than 1000 steps.\n");
    exit(EXIT_FAILURE);
  }

  universe final_u = naive_simulation(u, options.print_to_console, options.generate_images, options.consider_torus);

  if (!(options.print_to_console || options.generate_images))
  {
    printf("You did not request any output, here's at least the final state of the universe:\n");
    print_naive_cells(final_u);
  }

  free(u.cells);
  free(final_u.cells);

  return 0;
}
