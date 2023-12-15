#include "shell.h"

/**
 * _getenv - gets value of variable specified
 * as name in the environment
 * @name: name of variable
 *
 * Return: returns value if success, NULL if failure.
 */
char  *_getenv(const char *name)
{
	int i, value;
	char *token = NULL;
	char *str = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		str = _strdup(environ[i]);
		if (str == NULL)
		{
			free(str);
			str = NULL;
			printf("string duplication failed\n");
			return (NULL);
		}
		token = strtok(str, "=");
		value = _strcmp(token, name);
		if (value == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		free(str);
	}
	return (environ[i]);
}

