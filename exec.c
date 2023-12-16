#include "shell.h"

/**
 * exec - executes a file
 * @entry: command from user
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int exec(char **entry, char *argv[], int index)
{
	int value, status;
	pid_t child;
	char *path;

	path = search_file(entry[0]);
	if (path == NULL)
	{
		error_handler(argv[0], entry[0], index);
		free_array(entry);
		return (127);
	}
	child = fork();
	if (child == -1)
	{
		perror("fork failed\n");
	}
	else if (child == 0)
	{
		value = execve(path, entry, environ);
		if (value == -1)
			perror(argv[0]);
		free_array(entry);
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(entry);
		free(path);
		path = NULL;
	}
	return (0);
}
