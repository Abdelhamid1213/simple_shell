#include "shell.h"

/**
 * main - Entry point to the program
 * @ac: arguments count
 * @av: arguments vector
 * Return: 0 On Success
 */

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
	char *buffer = NULL, **tokens;
	size_t buff_size = 10;
	int char_count, status;
	pid_t pid;

	write(1, "$ ", 2);
	char_count = getline(&buffer, &buff_size, stdin);
	if (char_count == EOF)
	{
		perror("getline error\n");
		exit(EXIT_FAILURE);
	}
	buffer[char_count - 1] = '\0';
	tokens = tokenizer(buffer);

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
		wait(&status);

	return (0);
}
