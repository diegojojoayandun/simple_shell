#include "main.h"


/**
 * check_for_builtins - get the function corresponding to especifier
 * @args: duoble pinter, store the command line buffer
 * Return: return a function corresponding to especifier
 */
void (*check_for_builtins(char **args))(char **args)
{
	builtins_t builtins_list[] = {
		{"exit", __exit},
		{"env", __env},
		{NULL, NULL}};

	int i;

	if (args[0] == NULL)
	{
		free(args);
		exit(0);
	}

	for (i = 0; builtins_list[i].name != NULL ; i++)
	{
		if (_strcmp(args[0], builtins_list[i].name) == 0)
			break;
	}

	if (builtins_list[i].f != NULL)
		builtins_list[i].f(*args);

	return (builtins_list[i].f);
}

/**
 * __exit - exit program
 *
 * Return: void
 */
void __exit(char **ptr)
{
	free(ptr);
	exit(0);

}


/**
 * __env - prints the environmente vars
 *
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
