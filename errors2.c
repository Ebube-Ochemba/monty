#include "monty.h"

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
