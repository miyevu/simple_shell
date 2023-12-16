#ifndef SHELL_H
#define SHELL_H

/*standard libraries*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/*function prototypes*/
void my_print(char *message);
void print_to_error(char *str);
char *get_input(void);
char **assignment(int strnum, char *str);
char **get_token(char *line_read);
void free_array(char **ptr);
int exec(char **entry, char **argv, int index);
char *_getenv(char *name);
char *search_file(char *str);
void error_handler(char *name, char *input, int index);

/*support function prototypes*
void sup(char *ptr1, char *ptr2, char **ptr3);
void sup2(char *ptr1, char **ptr2);
void search_sup(char *ptr1, char *ptr2);
void check_for_null(char *str);
*/
/*string handlers*/
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int intlen(int num);
#endif
