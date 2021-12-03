#include "main.h"

/**
 * get_path - function
 *
 * @arg: args arg to find path
 *
 * Return: char pointer with the path
 */
char *get_path(char *arg)
{
	char *path, *token, *newpath;
	struct stat stats;

	if (stat(arg, &stats) == 0)
		return (arg);

	while (*environ != NULL)
	{
		if (_strcmp(*environ, "PATH") == 0)
			path =  *environ + _strlen("PATH") + 1;
		environ++;
	}

	arg = str_concat("/", arg);
	token = strtok(path, ":");

	while (token != NULL)
	{
		newpath = str_concat(token, arg);

		if (stat(newpath, &stats) == 0)
		{
			free(arg);
			return (newpath);
		}
		free(newpath);
		token = strtok(NULL, ":");
	}

	free(token);
	free(arg);
	return (arg);
}
