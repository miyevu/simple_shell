#include "shell.h"

/**
 * main - implementation of shell, entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits on failure or returns 1
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int i;
	int sig = 0;
	char *line_read = NULL;
	char **entry = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			my_print("#cisfun$ ");
		line_read = get_input();
		if (line_read == NULL)
		{
			if (isatty(STDIN_FILENO))
				my_print("\n");
			return (sig);
		}
		entry = get_token(line_read);
		if (entry == NULL)
			continue;
		for (i = 0; entry[i] != NULL; i++)
			printf("%s\n", entry[i]);
		sig = exec(entry, argv);
	}
	return (0);
}
