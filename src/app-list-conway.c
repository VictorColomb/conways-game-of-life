/**
 * @file app-list-conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an executable of a naive implementation of Conway's game of life
 * @date 2021-03-16
 *
 * __USAGE__ `./app-naive-conway [-ipte?] filename`
 * * `-?`: print source textfile formatting help
 * * `-p`: print simulation steps to console
 * * `-i`: generate image output for each steps
 * * `-t`: consider the universe as a torus
 * * `-e`: consider the universe as expandable (incompatible with a torus universe!)
 */

#include <stdio.h>

#include "list_universe.h"
#include "list_loader.h"
#include "list_conway.h"
#include "list_conway_expandable.h"
#include "list_optionsparser.h"

int main(int argc, char **argv)
{
  list_options options = parse_options(argc, argv);
  if (options.print_formatting_help)
  {
    do_print_formatting_help();
  }

  universe u = list_conway_load(options.filename);

  if (options.generate_images && u.step_nb > 1000)
  {
    linked_list_free(u.cells);
    fprintf(stderr, "[!] Cannot generate image output for more than 1000 steps.\n");
    exit(EXIT_FAILURE);
  }

  u = options.expandable ? list_simulation_expandable(u, options.print_to_console, options.generate_images) : list_simulation(u, options.print_to_console, options.generate_images, options.consider_torus);

  if (!(options.print_to_console || options.generate_images))
  {
    printf("You did not request any output, here's at least the final state of the universe:\n");
    print_list_cells(u);
  }

  linked_list_free(u.cells);
  return 0;
}
