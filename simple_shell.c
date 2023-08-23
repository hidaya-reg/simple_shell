#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	int n_char;
	bool is_interactive = isatty(STDIN_FILENO);
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("Eror: PATH environment variable not set");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		char *input = NULL;
		size_t input_size = 0;

		if (is_interactive)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		n_char = getline(&input, &input_size, stdin);
		if (n_char == -1)
		{
			if (is_interactive)
			{
				perror("Error in getline");
			}
			free(input);
			exit(0);
		}
		if (n_char == 1)
		{
			continue;
		}
		input[_strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}
		if (_strcmp(input, "env") == 0)
		{
			char **env = environ;
			
			while (*env)
			{

				write(STDOUT_FILENO, *env, _strlen(*env));
				write(STDOUT_FILENO, *env, strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}
			continue;
		}
		execute_cmd(input, path, is_interactive);
		free(input);
	}
	return (0);
}
