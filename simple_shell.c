#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	bool is_interactive = isatty(STDIN_FILENO);
	char **args, *input;
	int stat = 1;

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		else
			stat = 0;
		input = _getline();
		if (input[0] == '\0' || is_empty(input) == 1)
		{
			continue;
		}

		args = tokenize(input);

		if (_strcmp(args[0], "exit") == 0)
		{
			free(input);
			free(args);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			handle_env();
			free(args);
			stat = 0;
			continue;
		}
		else
			stat = check_execute_cmd(args, input);

		free(input);
		free(args);
		wait(&stat);
	}
	return (stat);
}
