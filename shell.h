#ifndef SHELL_H
#define SHELL_H

/*standard libraries*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

/*function prototypes*/
void my_print(char *message);
char *get_input(void);
char **assignment(int strnum, char *str);
char **get_token(char *line_read);
void free_array(char **ptr);
int exec(char **entry, char **argv);

/*string handlers*/
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
#endif
