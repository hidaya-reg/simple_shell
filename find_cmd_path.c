#include "shell.h"

/**
 * find_cmd_path - find the path of given cmd
 * @args: argument vector * @path: path variable
 * Return: cmd_path on succeess NULL in failure
 */

int find_cmd_path(char **args)
{
	char *path = getenv("PATH");
	char *token = _strtok(path, ":");
	struct stat buf;
	char *cmd_path;

	while (token != NULL)
	{
		cmd_path = build_cmd_path(*args, token);
		if (stat(cmd_path, &buf) == 0)
		{
			*args = strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		token = _strtok(NULL, ":");
	}
	free(path);
	free(token);
	/* cmd not found in PATH*/
	return (1);
}
