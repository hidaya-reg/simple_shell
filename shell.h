#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define BUFSIZE 1024
#define DELIMITER " \t\r\n\a"

void execute_cmd(char *input, char **env, char *path);
void file_stat(char *pathfile, struct stat *stat_input);
void tokenize(char *input, char **av);
bool find_cmd(char *cmd, char *path, char *result);
/* string functions*/
size_t _strlen(const char *str);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *str, int ch);
char *_strrchr(const char *str, int ch);

/* environment functions */
extern char **environ;
char *get_path();
#endif
