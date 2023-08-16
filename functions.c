#include "shell.h"

/**
 * tokenizer - split sting into tokens
 * @str: string to split
 * Return: splitted string
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
