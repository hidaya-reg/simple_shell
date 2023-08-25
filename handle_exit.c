#include "shell.h"

/**
 * handle_exit - handle 'exit' cmd
 * @args: argument vector
 * Return: void
 */

void handle_exit(char **args)
{
	int exit_stat = 0;

	if (args[1] != NULL)
	{
		exit_stat = _atoi(args[1]);
	}
	exit(exit_stat);
}
