#include "shell.h"
/**
 * _getline - read line from input
 * Return: buffer
 */
char *_getline()
{
	int bytes_read, i, buffer_size = BUFSIZE;
	char *buffer, *line_buffer = malloc(sizeof(char) * buffer_size);
	char current_char = 0;

	if (line_buffer == NULL)
	{
		free(line_buffer);
		return (NULL);
	}
	for (i = 0; current_char != EOF && current_char != '\n'; i++)
	{
		fflush(stdin);
		bytes_read = read(STDIN_FILENO, &current_char, 1);
		if (bytes_read == 0)
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		line_buffer[i] = current_char;
		if (line_buffer[0] == '\n')
			free_line(line_buffer);
		if (i >= buffer_size)
		{
			line_buffer = realloc(line_buffer, sizeof(char) * (buffer_size + 2));
			if (line_buffer == NULL)
			{
				free(line_buffer);
				return (NULL);
			}
		}
	}
	line_buffer[i] = '\0';
	if (is_empty(line_buffer))
		free_line(line_buffer);
	buffer = rm_space(line_buffer);
	free(line_buffer);
	return (buffer);
}
