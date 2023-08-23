#include "shell.h"

/**
 * _strcmp - function compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if they are equal, non 0 otherwise
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
