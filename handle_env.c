#include "shell.h"

/**
 * handle_env - print env variable
 * Return: void
 */

void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
