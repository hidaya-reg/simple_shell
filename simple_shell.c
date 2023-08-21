#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[BUFSIZE];
	char *args[BUFSIZE / 2 + 1];
	pid_t child_pid;
	int status, num_args;
	char *token;
	
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		/* Read user input*/
		if (fgets(input, BUFSIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		/* Remove newline character from input*/
		/* no need to remove newline since its part of DELIMITER */
		/*input[strcspn(input, "\n")] = '\0';*/

		/* Tokenize input into arguments*/
		token = strtok(input, DELIMITER);

		num_args = 0;
		while (token)
		{
			args[num_args] = token;
			num_args++;
			token = strtok(NULL, DELIMITER);
		}
		args[num_args] = NULL;
		
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			/* Child process*/
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error in execve:");
				return (1);
			}
		}
		else
		{
			/* Parent process*/
			wait(&status);
		}
	}

	return (0);
}
