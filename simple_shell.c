#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_INPUT_LENGTH 100
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH / 2 + 1];  // Command and arguments
    pid_t child_pid;
    int status;

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        // Read user input
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
        {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Tokenize input into arguments
        int num_args = 0;
        char *token = strtok(input, " ");
        while (token != NULL)
        {
            args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Error:");
            return 1;
        }

        if (child_pid == 0)
        {
            // Child process
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error in execve:");
                return 1;
            }
        }
        else
        {
            // Parent process
            wait(&status);
        }
    }

    return 0;
}
