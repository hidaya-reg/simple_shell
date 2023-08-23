#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	size_t input_size = 0;
	int n_char;
	char *input = NULL, *path = getenv("PATH");
	bool is_interactive = isatty(STDIN_FILENO);

	if (path == NULL)
	{
		perror("Eror: PATH environment variable not set");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
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
			exit(EXIT_FAILURE);
		}
		if (n_char == 1)
		{
			if (is_interactive)
				continue;
			else
				break;
		}
		if (n_char > 0 && input[n_char - 1] == '\n')
			input[n_char - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}
		if (strcmp(input, "env") == 0)
		{
			char **env = environ;
			while (*env)
			{
				write(STDOUT_FILENO, *env, strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}
			continue;
		}
		execute_cmd(input, path, is_interactive);
	}
	free(input);
	return (0);
}
