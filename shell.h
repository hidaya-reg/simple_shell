#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define BUFSIZE 1024
#define DELIMITER " \t\r\n\a"

void execute_cmd(char *input, char **env);
void file_stat(char *pathfile, struct stat *stat_input);
void tokenize(char *input, char **av);
#endif
