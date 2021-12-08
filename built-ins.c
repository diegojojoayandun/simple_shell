#include "main.h"


/**
 * check_for_builtins - get the function corresponding to built-in name
 *
 * @args: double pointer, store the command line buffer
 *
 * Return: return 1 it is a Built-in function, otherwise 0
 */
int check_for_builtins(char **args)
{
	builtins_t builtins_list[] = {
		{"exit", __exit},
		{"env", __env},
		{NULL, NULL}};

	int i = 0;

	if (args[0] == NULL)
	{
		free(args);
		exit(0);
	}

	for (; builtins_list[i].name != NULL ; i++)
		if (_strcmp(args[0], builtins_list[i].name) == 0)
			break;

	if (builtins_list[i].f != NULL)
	{
		builtins_list[i].f(*args);
		return (1);
	}
	return (0);
}

/**
 * __exit - Built-in function to allow exit from terminal
 *
 * @ptr: doouble pointer to be free
 *
 */
void __exit(char **ptr)
{
	free(ptr);
	exit(2);
}


/**
 * __env - prints the environmente vars
 *
 * Return: void
 */
void __env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i++]);
		_puts("\n");
	}
}
