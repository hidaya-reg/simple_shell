#include "shell.h"

/**
 * execute_path - execute using PATH
 * @args: vector of arguments
 * @path: path
 * Return: true if executed, false otherwise
 */

bool execute_path(char **args, char *path)
{
	char cmd_path[BUFSIZE];
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		_strcpy(cmd_path, token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, args[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			args[0] = cmd_path;
			return (execute_with_full_path(args));
		}
		token = strtok(NULL, ":");
	}
	return (false);
}

