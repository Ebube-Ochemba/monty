#include "monty.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int value = 0;

/**
 * main - The main function.
 * @argv: A 2D array of arguments passed to the program.
 * @argc: The number of arguments passed.
 * Return: An int.
 */

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	char *extension;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());

	extension = strrchr(argv[1], '.');
	if (extension == NULL || strcmp(extension, ".m") != 0)
		return (not_monty_file(argv[1]));

	if (access(argv[1], F_OK) == -1)
		return (access_error(argv[1]));

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (f_open_error(argv[1]));

	/* call interpeter and return int to update exit_code */
	exit_code = run_monty(fd);

	fclose(fd);
	return (exit_code);
}

/**
 * run_monty - Executes a Monty bytecode script.
 * @fd: File descriptor for an open Monty script.
 * Return: EXIT_SUCCESS on success or appropriate error code.
 */
int run_monty(FILE *fd)
{
	char *line = NULL, *opc = NULL, *arg = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 0, result = 0, exit_code = EXIT_SUCCESS;
	stack_t *stack = NULL, *temp;

	while ((read = getline(&line, &len, fd)) != -1)
	{
		line_number++;

		opc = strtok(line, " \t\r\n");

		if (opc == NULL || *opc == '#')
		{
			continue;
		}

		arg = strtok(NULL, " \t\r\n");
		result = get_opc(&stack, opc, arg, line_number);
		if (result == 1)
		{
			exit_code = push_error(line_number);
			break;
		}
		else if (result == 2)
		{
			exit_code = ins_error(opc, line_number);
			break;
		}
	}

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}

	free(line);
	return (exit_code);
}

/**
 * get_opc - Handles opcode selection.
 * @stack: A stack or queue.
 * @opc: The opcode to select.
 * @arg: The parameter passed to the opcode.
 * @line_number: The current line in file.
 * Return: 0 on success, else 1 0r 2 for error.
 */
int get_opc(stack_t **stack, char *opc, char *arg, int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(opc, op[i].opcode))
		{
			if (!strcmp(opc, "push"))
			{
				if (_isdigit(arg) == 1)
					value = atoi(arg);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}