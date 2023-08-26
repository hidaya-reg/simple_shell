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
int check_execute_cmd(char **args);
char *build_cmd_path(char *str1, char *str2);
int find_cmd_path(char **args);
int execute_cmd(char **args);
char *check_cmd(char **args);
void handle_exit(char **args);

void handle_env(char **args);
void file_stat(char *pathfile, struct stat *stat_input);
char **tokenize(char *input);

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
int _strncmp(const char *str1, const char *str2, size_t n);
bool is_delim(const char *str, char ch);
char *rm_space(char *input);
/*void rm_space(char **input);*/
int is_empty(char *line);
int _atoi(char *str);

/* environment functions */
extern char **environ;
char *get_path();
void rm_env(char *var_env);

char *_getline();
char *free_line(char *str);
#endif
