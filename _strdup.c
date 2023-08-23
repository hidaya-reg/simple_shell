#include "shell.h"

/**
 * _strdup - allocates memory for a new string
 * @str: string we want to copy
 * Return: poniter to the newly allocated string
 */

char *_strdup(const char *str)
{
	size_t len = 0, i;
	char *new_str;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	new_str = (char *)malloc(len + 1);

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);
}

