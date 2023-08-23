#include "shell.h"

/**
 * find_cmd - function to find comman in the PATH
 * @cmd: comand
 * @path: pathh
 * @result: result
 * Return: whether cmd is in path
 */

bool find_cmd(char *cmd, char *path, char *result)
{
	char *token = _strtok(path, ":");

	while (token != NULL)
	{
		_strcpy(result, token);
		_strcat(result, "/");
		_strcat(result, cmd);

		if (access(result, X_OK) == 0)
			return (true);
		token = _strtok(NULL, ":");
	}
	return (false);
}
