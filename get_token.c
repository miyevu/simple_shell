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
	char **entry = NULL;
	char *token = NULL;

	entry = malloc(sizeof(char *) * (strnum + 1));
	if (entry == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		entry[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	free(str);
	str = NULL;
	entry[i] = NULL;
	return (entry);
}
