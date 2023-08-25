#include "shell.h"

/**
 * handle_env - print env variable
 * @args: argument vector
 * Return: void
 */

void handle_env(char **args)
{
	if (args[1] == NULL)
	{
		char **env = environ;

		while (*env)
		{
			write(1, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	else
	{
		char *value = getenv(args[1]);

		if (value != NULL)
		{
			write(1, args[1], _strlen(args[1]));
			write(1, "=", 1);
			write(1, value, _strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			write(1, "Environment variable '", 22);
			write(1, args[1], _strlen(args[1]));
			write(1, "' not found\n", 11);
		}
	}
}
