#include "shell.h"

/**
 * _strspn - claculate length of given string
 * that consists from given character
 * @str: string to calculate its length
 * @accept: string containing characters to match
 * Return: length of str by accept
 */

size_t _strspn(const char *str, const char *accept)
{
	size_t len = 0;
	const char *s, *a;

	for (s = str; *s; s++)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				len++;
				break;
			}
		}
		if (*a == '\0')
			return (len);
	}
	return (len);
}
