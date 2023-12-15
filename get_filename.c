#include "shell.h"

/**
 * get_filename - takes in first argument and returns its filename
 *
 * @arg: first tokenized argument
 * Return: filename
 */
char *get_filename(char *arg)
{
	char *str = NULL, *token = NULL, *last_token, *mod_token = NULL;
	size_t i, len;
	int j;

	str = _strdup(arg);
	token = strtok(str, "/");
	while (token != NULL)
	{
		last_token = token;
		token = strtok(NULL, "/");
	}
	len = _strlen(last_token) + 2;
	mod_token = malloc(sizeof(char) * len);
	if (mod_token == NULL)
	{
		perror("Malloc failed");
	}
	/*inserting character at first position*/
	*mod_token = '/';
	j = 0;
	for (i = 1; i < len - 1; i++)
	{
		*(mod_token + i) = last_token[j];
		j++;
	}
	*(mod_token + i) = '\0';
	free(str);
	/*Remember to free mod_token after using it*/
	return (mod_token);
}
