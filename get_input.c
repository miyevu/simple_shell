#include "shell.h"

/**
 * get_input - get user input
 * @ptr: stores address of buffer
 * @ptrn: stores address of number
 *
 * Return: no return value
 */
void get_input(char **ptr, size_t *ptrn)
{
	ssize_t bytes_read;

	bytes_read = getline(ptr, ptrn, stdin);
	if (bytes_read == -1)
	{
		free(*ptr);
		exit(EXIT_FAILURE);
	}
	if ((*ptr)[bytes_read - 1] == '\n')
		(*ptr)[bytes_read - 1] = '\0';
}
