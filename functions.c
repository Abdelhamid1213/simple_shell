#include "shell.h"

/**
 * _getenv - ..
 * @env_var: ..
 * Return: ..
 */

char *_getenv(const char *env_var)
{
	char **env = environ;
	int i = 0;
	char *key;

	while (env[i])
	{
		key = strtok(env[i], "=");
		if (strcmp(env_var, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

/**
 * get_command - ..
 * @command: ..
 * Return: ..
 */

char *get_command(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);
		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);
		if (stat(cmd_full, &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * tokenizer - ..
 * @str: ..
 * Return: ..
 */

char **tokenizer(char *str)
{
	char *portion;
	char **portions = NULL;
	int i = 0;
	char *delim = " \n\t";

	portion = strtok(str, delim);
	while (portion)
	{
		i++;
		portions = realloc(portions, i * sizeof(char *));
		if (portions == NULL)
		{
			perror("Realloc Tokenizer");
			exit(EXIT_FAILURE);
		}
		portions[i - 1] = portion;
		portion = strtok(NULL, delim);
	}
	return (portions);
}

/**
 * env_builtin - ..
 * Return: ..
 */

void env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
