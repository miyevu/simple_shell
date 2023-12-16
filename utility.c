#include "shell.h"

/**
 * free_array - frees array of pointers
 * @ptr: pointer to array of pointers
 *
 * Return: no return value
 */
void free_array(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}

/**
 * error_handler - handles error
 *
 * return: no return value
 */
void error_handler(char *name, char *input, int index)
{
	char *indxx;
	char msg[] = ": not found\n";

	indxx = _itoa(index);
	print_to_error(name);
	print_to_error(": ");
	print_to_error(indxx);
	print_to_error(": ");
	print_to_error(input);
	print_to_error(msg);
	free(indxx);
}
