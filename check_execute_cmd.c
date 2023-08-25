#include "shell.h"
/**
 * check_execute_cmd - check and execute a command
 * @args: argumeny vector
 * @input: input string typed by user
 * Return: command satatus
 */

int check_execute_cmd(char **args, char *input)
{
	int status;
	pid_t child_pid;

	if (*args == NULL)
		return (EXIT_FAILURE);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (_strncmp(*args, "/", 1) != 0)	
		{
			if (find_cmd_path(args) != 0)
			{
				perror("command not found");
				exit(127);
			}
		}
		if (access(*args, R_OK) != 0)
		{
			perror("Error");
			free(args);
			free(input);
			args = NULL;
			input = NULL;
			exit(126);
		}
		if (execve(*args, args, environ) == -1)
			return (2);
		else
			return (0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (127);
}
