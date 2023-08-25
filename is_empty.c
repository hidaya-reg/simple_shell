#include "shell.h"

/**
 * is_empty - check if line is empty
 * @line: input line
 * Return: 1 if empty, 0 otherwise
 */

int is_empty(char *line)
{
	int i;

	for (i = 0; line[i] != '\n'; i++)
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}
