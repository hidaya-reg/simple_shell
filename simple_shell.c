#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	bool is_interactive = isatty(STDIN_FILENO);
	char **args, *input;
	int stat = 0;

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		input = _getline();

		if (input[0] == '\0')
			continue;

		args = tokenize(input);


		if (_strcmp(args[0], "exit") == 0)
		{
			free(input);
			free(args);
			exit(stat);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			handle_env();
			free(args);
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
