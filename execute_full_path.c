#include "shell.h"

/**
 * execute_full_path - execute full path command
 * @args: arg vector
 * Return: true if success, false otherwise
 */

bool execute_full_path(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error in fork");
		return (false);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error in execv");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Error in waitpid");
			return (false);
		}
	}
	return (true);
}
