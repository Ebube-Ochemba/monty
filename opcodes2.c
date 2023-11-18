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

/**
 * _div - Divides the second top element of the stack by the top element
 *        of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * _mul - Multiplies the second top element of the stack with the
 *        top element of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * _mod - Computes the rest of the division of the second top element of
 *        the stack by the top element of the stack.
 * @stack: A pointer to the node at the top of the stack.
 * @line_number: The line number in the monty file.
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
