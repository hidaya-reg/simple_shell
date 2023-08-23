#include "shell.h"

/*
 * execute_cmd - execute command
 * @input: argument vector
 * @env: environement
 * Return: void
 */

void execute_cmd(char *input, char **env)
{
	pid_t child_pid;
	int status;
	char *args[BUFSIZE / 2 + 1];

	tokenize(input, args);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error in fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error in execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Error in waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
