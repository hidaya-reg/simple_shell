#include "shell.h"

/**
 * execute_cmd - execute command
 * @input: input command
 * @path: path
 * @is_interactive: is via interactive mode or not
 * Return: void
 */

void execute_cmd(char *input, char *path, bool is_interactive)
{
	char *args[BUFSIZE / 2 + 1];

	tokenize(input, args);

	if (_strchr(args[0], '/') != NULL)
	{
		if (execute_full_path(args))
			return;
	}
	else
	{
		if (execute_path(args, path))
			return;
	}
	if (is_interactive)
		write(STDERR_FILENO, "Error cmd not found\n", 20);
	else
		perror("Error cmd not found");
}
