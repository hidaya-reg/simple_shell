#include "shell.h"

/**
 * get_path - function to find PATH varible
 * Return: PATH environment variable
 */

char *get_path()
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("Error in finding path");
		exit(EXIT_FAILURE);
	}
	return (path);
}
