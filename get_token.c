#include "shell.h"

/**
 * get_token - tokenizes string
 * @line_read: string read from line
 *
 * Return: returns pointer to pointer array on success
 * and NULL on failure
 */
char  **get_token(char *line_read)
{
	char *token, *str2, **assign_value;
	int str_num = 0;

	token = NULL;
	str2 = NULL;
	assign_value = NULL;
	if (!line_read)
		return (NULL);
	str2 = _strdup(line_read);
	token = strtok(str2, " ");
	if (token == NULL)
	{
		free(line_read);
		free(str2);
		str2 = NULL;
		line_read = NULL;
		return (NULL);
	}
	while (token != NULL)
	{
		str_num++;
		token = strtok(NULL, " ");
	}
	free(str2);
	str2 = NULL;
	assign_value = assignment(str_num, line_read);
	return (assign_value);
}

/**
 * assignment - puts tokens in array
 * @strnum: number of tokens
 * @str: string to be tokenized
 *
 * Return: pointer to initialized array of pointers
 */
char **assignment(int strnum, char *str)
{
	int i = 0;
	char **entry = NULL, *token = NULL, *str2 = NULL, *filename, *path;

	entry = malloc(sizeof(char *) * (strnum + 1));
	if (entry == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str2 = _strdup(str);
	if (str2 == NULL)
	{
		sup(str, str2, entry);
		return (NULL);
	}
	token = strtok(str2, " ");
	filename = get_filename(token);
	free(str2);
	str2 = NULL;
	path = search_file(filename);
	if (path == NULL)
	{
		sup2(str, entry);
		return (NULL);
	}
	entry[i] = strdup(path);
	free(path);
	path = NULL;
	token = strtok(str, " ");
	while ((token = strtok(NULL, " ")) != NULL)
	{
		i++;
		entry[i] = _strdup(token);
		token = strtok(NULL, " ");
	}
	free(str);
	str = NULL;
	entry[i + 1] = NULL;
	return (entry);
}

/**
 * sup - support function, frees 3 buffers at a time.
 * @ptr1: pointer 1
 * @ptr2: pointer 2
 * @ptr3: pointer 3
 * Return: no return value
 */
void sup(char *ptr1, char *ptr2, char **ptr3)
{
	free(ptr1);
	ptr1 = NULL;
	free(ptr2);
	ptr2 = NULL;
	free(ptr3);
	ptr3 = NULL;
}

/**
 * sup2 - support function 2, frees 2 buffers at a time
 * @ptr1: pointer 1
 * @ptr2: pointer 2
 * Return: no return value
 */
void sup2(char *ptr1, char **ptr2)
{
	free(ptr1);
	ptr1 = NULL;
	free(ptr2);
	ptr2 = NULL;
}

