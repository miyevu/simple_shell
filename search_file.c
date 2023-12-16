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
	size_t len, i, j;
	struct stat st;

	check_for_null(str);
	value = _getenv("PATH");
	dir = strtok(value, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + _strlen(str) + 1;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			perror("malloc failed");
			search_sup(str, value);
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
			search_sup(str, value);
			return (full_path);
		}
		else
		{
			dir = strtok(NULL, ":");
			free(full_path);
		}
	}
	search_sup(str, value);
	return (NULL);
}

/**
 * search_sup - search support function
 * @ptr1: pointer 1
 * @ptr2: pointer 2
 *
 * Return: no return value
 */
void search_sup(char *ptr1, char *ptr2)
{
	free(ptr1);
	ptr1 = NULL;
	free(ptr2);
	ptr2 = NULL;
}

/**
 * check_for_null - checks if string recieved is null
 * @str: string recieved
 *
 * Return: pointer to NULL if success
 */
void check_for_null(char *str)
{
	if (!str)
		return;
}
