#include "shell.h"

/**
 * _env - prints environment
 * @entry: array of pointers to be freed after built-in
 * @sig: address of sig integer
 * command execution
 *
 * Return: no return value.
 */
void _env(char **entry, int *sig)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		my_print(environ[i]);
		my_print("\n");
	}
	free_array(entry);
	*sig = 0;
}

/**
 * _exit - exits shell
 * @entry: array of pointers to be freed after built-in
 * command execution
 * @sig: address of sig integer
 *
 * Return:no return value
 */
void exit_shell(char **entry, int *sig)
{
	free_array(entry);
	exit(*sig);
}
