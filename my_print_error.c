#include "shell.h"

/**
 * print_to_error - prints to standard error
 * @str: string to print;
 *
 */
void print_to_error(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}
