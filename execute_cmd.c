#include "shell.h"
/**
 * execute_cmd - execute command
 * @input: argument vector
 * @env: environement
 * @path: PATH varibale
 * Return: void
 */

void execute_cmd(char *input, char **env, char *path)
{
	pid_t child_pid;
	int status;
	char *args[BUFSIZE / 2 + 1];
	char cmd_path[BUFSIZE];

	tokenize(input, args);
	if (_strchr(args[0], '/') != NULL)
	{
		char *cmd_name = _strrchr(args[0], '/');

		if (cmd_name != NULL)
			cmd_name++;
		else
			cmd_name = args[0];
		if (!find_cmd(cmd_name, path, cmd_path))
			perror("Error command  not ofound"), return;
	}
	else
		_strcpy(cmd_path, args[0]);

	child_pid = fork();
	if (child_pid == -1)
		perror("Error in fork"), exit(EXIT_FAILURE);
	if (child_pid == 0)
	{
		if (execve(cmd_path, args, env) == -1)
			perror("Error in execve"), exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
			perror("Error in waitpid"), exit(EXIT_FAILURE);
	}
}
