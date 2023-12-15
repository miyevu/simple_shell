#include "shell.h"

/**
 * exec - executes a file
 * @entry: command from user
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int exec(char **entry, char *argv[])
{
	int value, status;
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("fork failed\n");
	}
	else if (child == 0)
	{
		value = execve(entry[0], entry, environ);
		if (value == -1)
			perror(argv[0]);
		free_array(entry);
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(entry);
	}
	return (0);
}
