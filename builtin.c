#include "shell.h"

/**
 * builtin - ..
 * @command: ..
 * Return: ..
 */

int builtin(char *command)
{
	char *bt[] = {
		"exit", "env", NULL
	};
	int i;

	for (i = 0; bt[i]; i++)
	{
		if (_strcmp(command, bt[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - ..
 * @command: ..
 * @av: ..
 * @status: ..
 * @index: ..
 */

void handle_builtin(char **command, char **av, int *status, int index)
{
	(void) av;
	(void) index;

	if (_strcmp(command[0], "exit") == 0)
		shellexit(command, status);
	else if (_strcmp(command[0], "env") == 0)
		p_env(command, status);
}

/**
 * shellexit - ..
 * @command: ..
 * @status: ..
 */

void shellexit(char **command, int *status)
{
	ffree(command);
	exit(*status);
}

/**
 * p_env - ..
 * @command: ..
 * @status: ..
 */

void p_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	ffree(command);
	(*status) = 0;
}
