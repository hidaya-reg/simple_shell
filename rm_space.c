#include "shell.h"

/**
 * rm_space - remove space
 * @input: string to strip
 * Return: striped string
 */

char *rm_space(char *input)
{
	unsigned int i, j = 0;
	char *buffer = malloc(sizeof(char) * _strlen(input) + 1);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (i = 0; i < _strlen(input); i++)
	{
		if (input[i] != ' ')
		{
			buffer[j] = input[i];
			j++;
		}
	}

	buffer[j] = '\0';

	return (buffer);
}
