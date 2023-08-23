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
	char command[MAX_COMMAND_LENGTH];
	char *prompt = "$ ";

	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			continue;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
			execute_command(command);
	}

	return (0);
}
