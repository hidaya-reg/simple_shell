#include "shell.h"

/*
 * file_stat - check file status
 * @pathfile: path of file
 * @stat_input: stat of input string
 * Return: void
 */

void file_stat(char *cmd, struct stat *stat_input)
{
	if (stat(cmd, stat_input) == -1)
	{
		perror("Error in stat");
		exit(EXIT_FAILURE);
	}
}
