#include "monty.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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
	/* exit_code = "pass fd to function" */

	fclose(fd);
	return (exit_code);
}
