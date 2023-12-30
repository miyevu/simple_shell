#include "shell.h"

/**
 * is_builtin - checks if command is built-in
 * @entry: commnd entered
 *
 * Return: 1 if builtin, 0 if not
 */
int is_builtin(char *entry)
{
	char *builtins[] = {
		"cd", "env", "setenv", "cd", "exit", NULL
	};
	int i = 0;

	while (builtins[i] != NULL)
	{
		if (_strcmp(entry, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_builtin - handles builtin commands
 * @entry: array of pointers to strings, in this case the command entered
 * @sig: address of integer variable counting number of variations
 *
 * Return: no return value
 */
void handle_builtin(char **entry, int *sig)
{
	if (_strcmp(entry[0], "exit") == 0)
	{
		exit_shell(entry, sig);
	}
	else if (_strcmp(entry[0], "env") == 0)
		_env(entry, sig);
}
