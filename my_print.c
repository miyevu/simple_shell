#include "shell.h"

/**
 * my_print - prints string to standard output
 * @message: string
 *
 * Return: no return value
 */
void my_print(char *message)
{
	write(1, message, _strlen(message));
}
