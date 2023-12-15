#ifndef SHELL_H
#define SHELL_H

/*standard libraries*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*function prototypes*/
void my_print(const char *message);
void get_input(char **ptr, size_t *ptrn);
void exec(char *pathname);

#endif
