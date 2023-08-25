#include "shell.h"

/**
 * build_cmd_path - concatenate two strings by "/"
 * @str1: first string
 * @str2: second string
 * Return: concatenated both strings, NULL otherwise
 */

char *build_cmd_path(char *str1, char *str2)
{
	char *new_str;
	size_t len;

	len = _strlen(str1) + _strlen(str2) + 2;
	new_str = malloc(sizeof(char) * len);
	if (new_str == NULL)
	{
		perror("Memory allocation error");
		free(new_str);
		return (NULL);
	}

	memset(new_str, 0, len);

	new_str = _strcat(new_str, str2);
	new_str = _strcat(new_str, "/");
	new_str = _strcat(new_str, str1);
	return (new_str);
}
