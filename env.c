#include "shell.h"

/**
 * _getenv - ..
 * @var: ..
 * Return: ..
 */

char *_getenv(char *var)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}

/**
 * _getpath - ..
 * @command: ..
 * Return: ..
 */

char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
