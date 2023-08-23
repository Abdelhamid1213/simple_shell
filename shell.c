#include "shell.h"

/**
 * main - Entry point to the program
 * @ac: arguments count
 * @av: arguments vector
 * @env: environement variables
 * Return: 0 On Success
 */

int main(int ac, char __attribute__((unused)) **av, char **env)
{
	size_t buffer_size = 0;
	char *cmd, **args, *buffer = NULL;
	pid_t pid;
	int status, n_chars;

	(void)ac;

	while (1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		if (n_chars == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}

		if (n_chars != 1)
		{
			args = tokenizer(buffer);
			if (strcmp(args[0], "exit") == 0)
				exit(0);
			if (strcmp(args[0], "env") == 0)
				env_builtin();
			pid = fork();
			if (pid == 0)
			{
				cmd = get_command(args[0]);
				if (cmd)
					execve(cmd, args, env);
				else
					printf("Command not found\n");
				exit(0);
			}
			else
				wait(&status);
		}
	}
	return (0);
}
