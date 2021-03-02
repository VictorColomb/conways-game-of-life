/**
 * @file app-naive-conway.c
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Source code for an executable of a naive implementation of Conway's game of life
 * @date 2021-03-02
 *
 * USAGE: `./app-naive-conway [-ip?] filename`
 * * `-?`: print source textfile formatting help
 * * `-p`: print simulation steps to console
 * * `-i`: _don't_ generate images for each step
 * * `-t`: consider the universe as a torus
 */

#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_conway.h"
#include "naive_optionsparser.h"

bool print_formatting_help = false;
bool print_to_console = false;
bool generate_images = true;
bool consider_torus = false;

int main(int argc, char **argv)
{
  naive_options options = parse_options(argc, argv);
  if (options.print_formatting_help)
  {
    do_print_formatting_help();
  }

  return 0;
}
