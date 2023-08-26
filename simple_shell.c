#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char **args, *input;
	int stat = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		else
			stat = 0;
		input = _getline();
		if (input[0] == '\0' || is_empty(input) == 1)
			continue;
		args = tokenize(input);
		if (_strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(0);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			handle_env(args);
			free(input);
			free(args);
			continue;
		}
		else
			stat = check_execute_cmd(args);
		free(input);
		free(args);
	}
	return (stat);
}
