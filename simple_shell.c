#include "shell.h"

/**
 * main - Entry point of the program
 * @ac: argument count
 * @av: argument vector
 * @env: environment
 * Return: Always 0 (Success)
 */
int main(int ac, char *av[], char **env)
{
	size_t input_size = 0, n_char;
	char *input = NULL;
	bool from_pipe = false;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;

		write(1, "#cisfun$ ", 9);

		n_char = getline(&input, &input_size, stdin);
		if (n_char == -1)
		{
			perror("Error in getline");
			free(input);
			exit(EXIT_FAILURE);
		}

		if (n_char > 0 && input[n_char - 1] == '\n')
			input[n_char - 1] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}

		execute_cmd(input, env);
	}
	free(input);
	return (0);
}
