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
	fprintf(stderr, "Error: Can't open file %s\n", file);
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
 * malloc_error - Prints error messasge for malloc failure.
 * Return: EXIT_FAILURE.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
