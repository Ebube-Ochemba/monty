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
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - Prints the value at the top of a stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - Removes the top element of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
