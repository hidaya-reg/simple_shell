#include "shell.h"

/**
 * _strcat - append characters from source string
 * destination string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the modified dest string
 */

char *_strcat(char *dest, const char *src)
{
	char *org_dest = dest;

	while (*dest != '\0')
		dest++;

	while ((*dest++ = *src++) != '\0')
	{
	}
	return (org_dest);
}
