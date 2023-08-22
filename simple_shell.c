#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	size_t input_size = 0, n_char;
	char *input = NULL, *token;
	char *args[BUFSIZE / 2 + 1];
	pid_t child_pid;
	int status, num_args, i;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);

		/* Read user input*/
		n_char = getline(&input, &input_size, stdin);
		if (n_char == -1)
		{
			perror("Error in getline");
			free(input);
			exit(EXIT_FAILURE);
		}
		/*if (n_char == 1)
		{
			continue;
		}*/

		i = 0;
		while (input[i])
		{
		       if (input[i] == '\n')
			       input[n_char - 1] = 0;
		       i++;
		}
		/*args = malloc(sizeof(char *) * BUFSIZE / 2 + 1);*/

		/* Tokenize input into arguments*/
		token = strtok(input, " ");

		/* Get number of tokens*/
		num_args = 0;
		while (token)
		{
			args[num_args] = token;
			num_args++;
			token = strtok(NULL, " ");
		}
		args[num_args] = NULL;


		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error in fork");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			/* Child process*/
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error in execve");
				free(input);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process*/
			wait(&status);
		}
	}
	free(input);
	return (0);
}
