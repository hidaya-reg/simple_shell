#include "shell.h"
/**
 * check_execute_cmd - check and execute a command
 * @args: argumeny vector
 * @input: input string typed by user
 * Return: command satatus
 */
int check_execute_cmd(char **args)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (_strncmp(*args, "/", 1) != 0 && _strncmp(*args, "./", 2) != 0)
		{
			if (find_cmd_path(args) != 0)
			{
				perror("File not found");
				exit(127);
			}
		}
		if (access(args[0], X_OK) != 0)
		{
			perror("File is not executable");
			exit(126);
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (127);
}
