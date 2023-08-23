#include "shell.h"

/**
 * _strlen - function that calculate length of str
 * @str: null-terminated string
 * Return: length of str
 */

size_t _strlen(const char *str)
{
	size_t l = 0;

	while (str[l])
		l++;
	return (l);
}
