#include "shell.h"

/**
 * _strchr - search for the first occurence
 * of a character
 * @str: string we search in
 * @ch: character we are looking for
 * Return: pointer to the first occurrence of ch
 */

char *_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
