#include "shell.h"

/**
 * handle_env - print env variable
 * Return: void
 */

void handle_env()
{
	char **env = environ;
	size_t i;

	if (!env)
		return;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

}
