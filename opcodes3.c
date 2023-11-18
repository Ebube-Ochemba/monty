#include "monty.h"

/**
 * _nop - Doesn’t do anything.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);

}


/**
 * _pstr - Prints the string starting at the top of the stack,
 *        followed by a new line.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		printf("\n");
		return;
	}

	while (temp != NULL)
	{
		if (temp->n == 0)
			break;
		if (temp->n < 0 || temp->n > 127)
		{
			fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
