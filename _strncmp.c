#include "shell.h"

/**
 * _strncmp - compares n characters of 2 strings
 * @str1: first string
 * @str2: second string
 * @n: number of characters
 * Return: 1 on success, 0 otherwise
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);

	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}
	return (0);
}
