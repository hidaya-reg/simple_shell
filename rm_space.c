#include "shell.h"

/*
 * rm_space - remove leading space
 * @input: input
 * Return: strimed input
 */

char *rm_space(char *input)
{
	int i = 0;

	while (input[i] == ' ')
		i++;

	return (_strdup(input + i));
}
