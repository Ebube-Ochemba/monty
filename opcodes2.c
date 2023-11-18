#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->n += temp->n;
	free(temp);
	(*stack)->next = temp->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;
}
