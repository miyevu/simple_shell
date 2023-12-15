#include "shell.h"

/**
 * search_file - Searches for a file in directories specified by PATH
 * @str: The file to search for
 *
 * Return: The full path of the file if found, NULL otherwise
 */
char *search_file(char *str)
{
	char *value, *full_path, *cp, *dir;
	size_t len, i, j;
	struct stat st;

	value = _getenv("PATH");
	cp = _strdup(value);
	if (cp == NULL)
	{
		perror("strdup failed");
		return (NULL);
	}
	dir = strtok(cp, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + _strlen(str) + 1;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			perror("malloc failed");
			free(cp);
			free(str);
			return (NULL);
		}
		for (i = 0; i < strlen(dir); i++)
			*(full_path + i) = dir[i];
		j = 0;
		while (i < len - 1)
		{
			*(full_path + i) = str[j];
			j++;
			i++;
		}
		*(full_path + i) = '\0';
		if (stat(full_path, &st) == 0)
		{
			free(str);
			free(cp);
			return (full_path);
		}
		else
		{
			dir = strtok(NULL, ":");
			free(full_path);
		}
	}
	free(cp);
	free(str);
	return (NULL);
}

