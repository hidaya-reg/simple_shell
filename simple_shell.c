#include "shell.h"

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */

int main(void)
{
	size_t input_size = 0, n_char;
	char *input = NULL;
	char *path = get_path();

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		n_char = getline(&input, &input_size, stdin);
		if (n_char == -1)
		{
			perror("Error in getline");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (n_char == 1)
			continue;

		if (n_char > 0 && input[n_char - 1] == '\n')
			input[n_char - 1] = '\0';

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}

		execute_cmd(input, environ, path);
	}
	free(input);
	return (0);
}
