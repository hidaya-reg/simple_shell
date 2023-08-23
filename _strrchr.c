#include "shell.h"

/**
 * _strrchr - search for the las occurence of character
 * @str: string to look for
 * @ch: character we look for in str
 * Return: pointer to the last occurrence of ch
 */

char *_strrchr(const char *str, int ch)
{
	const char *last = NULL;

	while (*str)
	{
		if (*str == ch)
			last = str;
		str++;
	}
	return ((char *)last);
}
