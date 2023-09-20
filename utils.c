#include "shell.h"

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _itoa - ..
 * @n: ..
 * Return: ..
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * rev_str - ..
 * @str: ..
 * @len: ..
 */

void rev_str(char *str, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
