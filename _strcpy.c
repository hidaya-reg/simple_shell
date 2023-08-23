#include "shell.h"

/**
 * _strcpy - copy a string from src to dest
 * @src: source string
 * @dest: destination pointer
 * Return: original destination
 */

char *_strcpy(char *dest, const char *src)
{
	char *org_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	dest = '\0';

	return (org_dest);
}
