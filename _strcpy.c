#include "shell.h"

/**
 * _strcpy - copy a string from src to dest
 * @dest: destination pointer
 * @src: source string
 * Return: original destination
 */

char *_strcpy(char *dest, const char *src)
{
	char *org_dest = dest;

	while ((*dest++ = *src++) != '\0')
	{
	}

	return (org_dest);
}
