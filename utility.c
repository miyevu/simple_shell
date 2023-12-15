#include "shell.h"

/**
 * free_array - frees array of pointers
 * @ptr: pointer to array of pointers
 *
 * Return: no return value
 */
void free_array(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}
