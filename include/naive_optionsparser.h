/**
 * @file naive_optionsparser.h
 * @author Victor Colomb (vic.col@hotmail.fr)
 * @brief Header file for an option parser for a naive implementation of Conway's game of life
 * @date 2021-03-02
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct naive_options naive_options;

/**
 * @brief Structure used to store the command-line options entered by the user.
 */
struct naive_options {
  bool print_formatting_help;
  bool print_to_console;
  bool generate_images;
  bool consider_torus;
  char *filename;
};

naive_options naive_default_options();

/**
 * @brief Print usage help message and crash program.
 *
 * @param exec_name executable name (usually from argv[0])
 */
void print_usage(char *exec_name);

/**
 * @brief Print source textfile formatting help and crash program.
 */
void do_print_formatting_help();

/**
 * @brief Parse options from command line arguments.
 *
 * Function will modify `print_formatting_help`, `print_to_console` and `generate_images` booleans accordingly and return the first positional argument, which should be the filename.
 */
naive_options parse_options(int argc, char **argv);
