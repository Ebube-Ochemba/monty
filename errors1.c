#include "monty.h"

/**
 * usage_error - Prints Usage error message.
 * Return: EXIT_FAILURE.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * access_error - Prints Acces error message.
 * @file: The name of the file passed to the program.
 * Return: EXIT_FAILURE.
 */
int access_error(char *file)
{
	fprintf(stderr, "Error: Can't access file %s\n", file);
	return (EXIT_FAILURE);
}


/**
 * f_open_error - Prints f_open_error message.
 * @file: The name of the file passed to the program.
 * Return: EXIT_FAILURE.
 */
int f_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}

/**
 * not_monty_file - Prints error message in case of wrong bytecode.
 * @file: The name of the file passed to the program.
 * Return: EXIT_FAILURE.
 */
int not_monty_file(char *file)
{
	fprintf(stderr, "Error: Not a Monty bytecode file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * a
 * R
 */

