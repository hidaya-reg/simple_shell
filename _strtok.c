#include "shell.h"
/**
 * _strtok - split a string and returns pointer to next token
 * @str: string to split
 * @delim: delimiter
 * Return: pointer to next token
 */

char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *start, *end;

	if (str != NULL)
		last = str;
	else if (last == NULL)
		return (NULL);

	start = last;
	end = start;
	while (*end != '\0' && _strchr(delim, *end) == NULL)
		end++;

	if (*end == '\0')
		last = NULL;
	else
	{
		*end = '\0';
		last = end + 1;
	}
	return (start);
}
