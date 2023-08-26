#include "shell.h"
/**
 * free_line - free line
 * @str: str
 * Return: empty string
 */

char *free_line(char *str)
{
	free(str);
	return ("\0");
}
