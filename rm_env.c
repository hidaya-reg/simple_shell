#include "shell.h"

/**
 * rm_env - remove all variables except one
 * @var_env: env we want to keep
 * Return: void
 */

void rm_env(char *var_env)
{
	char **current;
	int i, j = 0;

	current = malloc(sizeof(char *) * _strlen(var_env) + 2);

	if (current == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], var_env, _strlen(var_env) == 0))
		{
			current[j] = _strdup(environ[i]);
			j++;
		}
	}
	current[j] = NULL;

	for (i = 0; environ[i] != NULL; i++)
		free(environ[i]);
	free(environ);
	environ = current;
}
