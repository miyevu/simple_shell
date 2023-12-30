#include "shell.h"

/**
 * search_file - Searches for a file in directories specified by PATH
 * @str: The file to search for
 *
 * Return: The full path of the file if found, NULL otherwise
 */
char *search_file(char *str)
{
	char *value, *full_path, *dir;
	int len, i;
	struct stat st;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
		{
			if (stat(str, &st) == 0)
				return (_strdup(str));
			return (NULL);
		}
	}
	value = _getenv("PATH");
	if (value == NULL)
		return (NULL);
	dir = strtok(value, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + _strlen(str) + 2;
		full_path = malloc(len);
		if (full_path != NULL)
		{
			_strcpy(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, str);
			if (stat(full_path, &st) == 0)
			{
				free(value);
				return (full_path);
			}
			free(full_path);
			full_path = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(value);
	return (NULL);
}
