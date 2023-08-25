#include "shell.h"

/**
 * rm_space - remove space
 * @input: string to strip
 * Return: striped string
 */

char *rm_space(char *input)
{
	int i = 0;

	while (input[i] == ' ')
		i++;

	return (_strdup(input + i));
}
