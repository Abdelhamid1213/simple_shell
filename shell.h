#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *env_var);
char *get_command(char *command);
char **tokenizer(char *str);
void env_builtin(void);

#endif
