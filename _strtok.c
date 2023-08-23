#include "shell.h"
/**
 * _strtok - split a string and returns pointer to next token
 * @str: string to split
 * @delim: delimiter
 * Return: pointer to next token
 */

char *_strtok(char *str, const char *delim)
{
	char *current = NULL;
	char *start = NULL;

	if (str != NULL)
		current = str;
	else if (current == NULL)
		return (NULL);
	while (*current)
	{
		bool is_delim = false;

		for (const char *d = delim; *d; d++)
		{
			if (*current == *d)
			{
				is_delim = true, break;
			}
		}
		if (is_delim)
		{
			*current = '\0';
			if (start != NULL)
			{
				char *token = start;

				start = NULL;
				current++;
				return (token);
			}
			else
				current++;
		}
		else
		{
			if (start == NULL)
				start = current;
			current++;
		}
	}
	return (start);
}
