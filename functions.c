#include "shell.h"

/**
 * execute_command - ..
 * @command: ..
 * Return: ..
 */

void execute_command(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
		perror("fork");

	else if (pid == 0)
	{
		char *token = strtok((char *)command, " ");
		char *args[MAX_COMMAND_LENGTH];
		int arg_count = 0;

		while (token != NULL)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

		perror("execvp");
		_exit(EXIT_FAILURE);
	}
	else
	{ 
		int status;
		waitpid(pid, &status, 0);
	}
}
