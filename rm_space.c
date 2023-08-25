#include "shell.h"

/**
 * rm_space - remove space
 * @input: string to strip
 * Return: striped string
 */

char *rm_space(char *input)
{
	int i, j;
	char *buffer;

	for (i = 0; input[i] == ' '; i++)
		;
	buffer = malloc(sizeof(char) * _strlen(input) - i + 1);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (; input[i + 1] != '\0'; i++)
	{
		buffer[j] = input[i];
		j++;
	}
	buffer[j] = '\0';
	if (buffer[0] == '\0')
	{
		free(buffer);
		return ("\0");
	}
	return (buffer);
}
