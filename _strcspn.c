#include "shell.h"

/**
 * _strcspn - calculates length of given string that
 * does not contain any character of reject
 * @str: given string
 * @reject: tif found in string we don't count it
 * Return: length of str without reject
 */

size_t _strcspn(const char *str, const char *reject)
{
	size_t len = 0;
	const char *s, *r;

	for (s = str; *s; s++)
	{
		for (r = reject; *r; r++)
		{
			if (*s == *r)
				return (len);
		}
		len++;
	}
	return (len);
}
