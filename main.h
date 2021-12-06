#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFSIZE 64

/**
 * struct built_ins - Associate a command with its funtion
 *
 * @name: corresponding to command name
 * @f: function pointer to corresponfind function
 * Description: the mainly purpouse is matching a command with its
 * correspondig function which is a function pointer.
 */
typedef struct built_ins
{
	char *name;
	void (*f)();
} builtins_t;

extern char **environ;
char *shell_name;
unsigned int line_counter;
/* strings */
int _strlen(const char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
int _puts(char *envi);
int _putchar(char c);
void _puts_number(int size);

char *get_path(char *command);
char *_getenv(char *input);
char **tokenize_line(char *line);
char *read_line(void);
int exec_line(char **args);

/* built-ins */
void __exit(char **ptr);
void __env(void);
void (*check_for_builtins(char **args))(char **args);
void _free(char **d_pointer);
void __error(char *arg, int size, char *command);

#endif
