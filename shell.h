#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \t\n"

extern char **environ;

/* functions.c */
char *get_l(void);
char **tokenize(char *line);
int exec(char **command, char **av);

/* string.c */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/* realloc.c */
void ffree(char **pp);

#endif
