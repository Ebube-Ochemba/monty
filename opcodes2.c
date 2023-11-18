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

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * _sub - Subtracts the top element of the stack from the second top
 *        element of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n - (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
