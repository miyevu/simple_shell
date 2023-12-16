#include "shell.h"

/**
 * _getenv - gets value of variable specified
 * as name in the environment
 * @name: name of variable
 *
 * Return: returns value if success, NULL if failure.
 */
char  *_getenv(char *name)
{
	int i, value;
	char *token = NULL;
	char *str = NULL;
	char *result = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		str = strdup(environ[i]);
		token = strtok(str, "=");
		value = _strcmp(token, name);
		if (value == 0)
		{
			result = strdup(token = strtok(NULL, "="));
			free(str);
			str = NULL;
			return (result);
		}
		free(str);
		str = NULL;
	}
	free(str);
	str = NULL;
	return (environ[i]);
}

