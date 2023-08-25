#include "shell.h"

/**
 * is_delim - check if string contain character
 * @str: string
 * @ch: character
 * Return: true on succes, false otherwise
 */
bool is_delim(const char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (true);
		str++;
	}
	return (false);
}
