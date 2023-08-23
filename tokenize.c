#include "shell.h"

/**
 * tokenize - split input string to tokens
 * @input: input string
 * @av: argument vector
 * Return: void
 */

void tokenize(char *input, char **av)
{
	char *token;
	int num_args = 0;

	token = _strtok(input, " ");
	while (token)
	{
		av[num_args] = token;
		token = _strtok(NULL, " ");
		num_args++;
	}
	av[num_args] = NULL;
}
