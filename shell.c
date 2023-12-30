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
	int sig = 0, index = 0;
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
		index += 1;
		entry = get_token(line_read);
		if (entry == NULL)
			continue;

		if (is_builtin(entry[0]) == 1)
			handle_builtin(entry, &sig);
		else
			sig = exec(entry, argv, index);
	}
	return (0);
}
