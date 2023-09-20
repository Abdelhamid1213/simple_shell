#include "shell.h"

/**
 * main - Entry point to the program
 * @ac: arguments count
 * @av: arguments vector
 * Return: 0 On Success
 */

int main(int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void)ac;

	while (1)
	{
		line = get_l();
		if (!line)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = tokenize(line);
		if (command == NULL)
			continue;

		status = exec(command, av);
	}
	return (0);
}
