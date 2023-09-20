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
 * Return: ..
 */

int exec(char **command, char **av)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			ffree(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		ffree(command);
	}
	return (WEXITSTATUS(status));
}
