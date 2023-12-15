#include "shell.h"

/**
 * get_input - get user input
 *
 * Return: no return value
 */
char *get_input(void)
{
	ssize_t bytes_read;
	char *buffer = NULL;
	size_t n = 0;

	bytes_read = getline(&buffer, &n, stdin);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[bytes_read - 1] == '\n')
		buffer[bytes_read - 1] = '\0';
	return (buffer);
}
