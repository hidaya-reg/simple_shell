#include "shell.h"

/**
 * tokenize - split input string to tokens
 * @input: input string
 * Return: arguments
 */

char **tokenize(char *input)
{
	char **av;
	char *token;
	int num_args = 0;
	int input_size = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);

	if (input == NULL)
		return (NULL);

	av = malloc(sizeof(char *) * input_size);
	if (!av)
	{
		free(av);
		perror("Error");
		return (NULL);
	}

	token = strtok(input, "\n\t\r\a ");

	while (token != NULL)
	{
		av[num_args] = token;
		token = strtok(NULL, "\n\t\r\a ");
		num_args++;
	}
	av[num_args] = NULL;
	return (av);
}
