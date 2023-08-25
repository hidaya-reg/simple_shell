#include "shell.h"
/**
 * _atoi - convert string to integer
 * @str: string to convert
 * Return: converted integer
 */

int _atoi(char *str)
{
	int result = 0;
	int sign = 1, i;
	bool found = false;
	char c;

	for (i = 0; str[i] != '\0'; ++i)
	{
		c = str[i];
		if (c == ' ' && found)
			break;

		if (c == '-' && !found)
		{
			sign = -1;
			found = true;
			continue;
		}

		if (c >= '0' && c <= '9')
		{
			found = true;
			result = result * 10 + (c - '0');
		}
		else
			break;
	}
	return (result * sign);
}

