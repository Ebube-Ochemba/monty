#include "monty.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: The character to be checked.
 *
 * Return: 1 if c is a digit, else 0.
 */

int _isdigit(char *c)
{
	char *tmp = c;

	if (c == NULL)
		return (0);
	if (*tmp == '-')
		tmp++;

	for (; *tmp != '\0'; tmp++)
	{
		if ((*tmp < '0') || (*tmp > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * create_node - Creates a new node.
 * @n: The value to add to created node.
 * Return: A new node.
 */
stack_t *create_node(int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_error();

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
