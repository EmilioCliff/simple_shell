#ifndef _MAIN_H_
#define _MAIN_H_
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
void free_all(void *ptr);
void _printf(char *format, ...);
char *_strcat(char *dest, const char *src);
char *_getenv(const char *env);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *argv_given, char *command);
void print_dir(void);
char *find_argv_in_path(char *path, char *argv);
int _strlen(const char *str);
void _strcpy(char *dest, char *src);
#endif
