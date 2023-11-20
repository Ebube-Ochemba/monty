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
 * malloc_error - Prints error messasge for malloc failure.
 * Return: EXIT_FAILURE.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * push_error - Prints Usage error message.
 * @line_number: The current line in the file.
 * Return: EXIT_FAILURE.
 */
int push_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * ins_error - Prints error message for invalid instruction.
 * @line_number: The current line in the file.
 * @opc: The opcode passed.
 * Return: EXIT_FAILURE.
 */
int ins_error(char *opc, int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
	return (EXIT_FAILURE);
}
