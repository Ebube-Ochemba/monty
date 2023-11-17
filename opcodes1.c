#include "monty.h"

int value;

/**
 * _push - Pushes item to stack or queue.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = create_node(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - Prints the elements of a stack
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
