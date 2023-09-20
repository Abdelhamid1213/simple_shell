#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define DELIM " \t\n"

extern char **environ;

/* builtin.c */
int builtin(char *command);
void handle_builtin(char **command, char **av, int *status, int index);
void shellexit(char **command, int *status);
void p_env(char **command, int *status);

/* env.c */
char *_getenv(char *var);
char *_getpath(char *command);

/* functions.c */
char *get_l(void);
char **tokenize(char *line);
int exec(char **command, char **av, int index);
void p_error(char *name, char *command, int index);

/* string.c */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/* utils.c */
void ffree(char **pp);
char *_itoa(int n);
void rev_str(char *str, int len);

#endif
