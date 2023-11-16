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
