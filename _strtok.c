#include "shell.h"
/**
 * _strtok - split a string and returns pointer to next token
 * @str: string to split
 * @delim: delimiter
 * Return: pointer to next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	static char *cursor;
	unsigned int i;

	if (str != NULL)
		cursor = str;
	next_token = cursor;
	if (next_token == NULL)
		return (NULL);
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (is_delim(delim, next_token[i]) == 0)
			break;
	}
	if (cursor[i] == '\0')
	{
		cursor = NULL;
		return (NULL);
	}
	next_token = cursor + i;
	cursor = next_token;
	for (i = 0; cursor[i] != '\0'; i++)
	{
		if (is_delim(delim, cursor[i]) == 1)
			break;
	}
	if (cursor[i] == '\0')
		cursor = NULL;
	else
	{
		cursor[i] = '\0';
		cursor = cursor + i + 1;
		if (*cursor == '\0')
			cursor = NULL;
	}
	return (next_token);
}

