#include "shell.h"

/**
 * execute_cmd - execute command
 * @args: argument array
 * Return: status of execution
 */

int execute_cmd(char **args)
{
	if (execve(*args, args, environ) == -1)
		return (2);
	else
		return (0);
}
