/**
 * @file naive_optionsparser.c
 * @author your name (you@domain.com)
 * @brief Source file for an options parser for a naive implementation of Conway's game of life
 * @date 2021-03-02
 */

#include "naive_optionsparser.h"

naive_options naive_default_options()
{
  naive_options defaults;

  defaults.consider_torus = false;
  defaults.generate_images = true;
  defaults.print_formatting_help = false;
  defaults.print_to_console = false;

  return defaults;
}

void print_usage(char *exec_name)
{
  fprintf(stderr, "USAGE: %s [-ipt?] filename\nOptions:\n  -i: DON'T generate images for each step\n  -p: print simulation steps to console\n  -t: consider the universe as a torus\n  -?: print source textfile formatting help\n  filename: source textfile to load universe from\n", exec_name);
  exit(EXIT_FAILURE);
}

void do_print_formatting_help()
{
  printf("Source textfiles should be formatted as follows:\n  width height\n  number_of_steps\n  cell structure\n\nIn the cell structure, a dead cell should be represented by . and a live cell by o.\n\nHere is an example for a 3x4 structure:\n3 4\n3\n.o..\n..o.\nooo.\n");
  exit(EXIT_SUCCESS);
}

naive_options parse_options(int argc, char **argv)
{
  naive_options options = naive_default_options();

  // go through all keyword options (options starting with with -)
  int opt_idx;
  for (opt_idx = 1; opt_idx < argc && argv[opt_idx][0] == '-'; ++opt_idx)
  {
    int idx = 1;
    char opt = argv[opt_idx][idx];
    while (opt != '\0')
    {
      switch (opt)
      {
      case '?':
        options.print_formatting_help = true;
        break;
      case 'p':
        options.print_to_console = true;
        break;
      case 'i':
        options.generate_images = false;
        break;
      case 't':
        options.consider_torus = true;
        break;
      default:
        print_usage(argv[0]);
      }

      ++idx;
      opt = argv[opt_idx][idx];
    }
  }

  // here, argv[opt_idx] points to the first positional argument, which should be the filename
  char *filename = argv[opt_idx];
  if (filename == NULL)
  {
    printf("[!] Missing filename argument\n");
    print_usage(argv[0]);
  }
  options.filename = filename;

  return options;
}
