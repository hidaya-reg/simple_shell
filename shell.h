#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#define BUFSIZE 1024
#define DELIMITER " \t\r\n\a"

/* excution functions */
bool execute_full_path(char **args);
bool execute_path(char**args, char *path);
void execute_cmd(char *input, char *path, bool is_interactive);

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
size_t _strspn(const char *str, const char *accept);
size_t _strcspn(const char *str, const char *reject);
char *_strdup(const char *str);

/* environment functions */
extern char **environ;
char *get_path();
#endif
