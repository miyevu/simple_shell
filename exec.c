#include "shell.h"

/**
 * exec - executes a file
 * @pathname: path string
 *
 * Return: no return value
 */
void exec(char *pathname)
{
	int value;
	pid_t child;
	char *argv[] = {NULL};

	child = fork();
	if (child == -1)
	{
		perror("fork failed\n");
	}
	else if (child == 0)
	{
		value = execve(pathname, argv, NULL);
		if (value == -1)
			perror("./shell");
	}
	else
	{
		wait(NULL);
	}
	free(pathname);
}
