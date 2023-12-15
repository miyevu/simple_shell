#include "shell.h"

/**
 * main - implementation of shell, entry point
 *
 * Return: 0 on success, exits on failure or returns 1
 */
int main(void)
{
	char *buffer;
	size_t buffer_size;

	buffer = NULL;
	buffer_size = 0;
	while (1)
	{
		my_print("#cisfun$ ");
		get_input(&buffer, &buffer_size);
		exec(buffer);
		buffer = NULL;
	}
	return (0);
}
