#include "shell.h"

/**
 * get_l - ..
 * Return: ..
 */

char *get_l(void)
{
	char *buff = NULL;
	size_t l = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&buff, &l, stdin);
	if (n == -1)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

/**
 * tokenize - ..
 * @line: ..
 * Return: ..
 */

char **tokenize(char *line)
{
	char *token = NULL, *lline = NULL, **command = NULL;
	int count = 0, i = 0;

	if (line == NULL)
		return (NULL);
	lline = _strdup(line);
	token = strtok(lline, DELIM);
	if (!token)
	{
		free(line), line = NULL;
		free(lline), lline = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(lline), lline = NULL;

	command = malloc(sizeof(char *) * (count + 1));
	if (command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}

/**
 * exec - ..
 * @command: ..
 * @av: ..
 * @index: ..
 * Return: ..
 */

int exec(char **command, char **av, int index)
{
	pid_t child;
	int status;
	char *full_cmd;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		p_error(av[0], command[0], index);
		ffree(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			ffree(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		ffree(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}


/**
 * p_error - ..
 * @name: ..
 * @command: ..
 * @index: ..
 */

void p_error(char *name, char *command, int index)
{
	char *idx, msg[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx), idx = NULL;
}
