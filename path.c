#include "main.h"

/**
 * _getenv - retrieves env variable that matches input string
* @input: input string
* Return: string of env variable
 */
char *_getenv(char *input)
{
	char *tok, *path;

	while (*environ)
	{
		tok = strtok(*environ, "=");
		if (_strcmp(tok, input) == 0)
		{
			path = strtok(NULL, "=");
			return (path);
		}
		environ++;
	}
	return (NULL);
}

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

	path = _getenv("PATH");

	arg = str_concat("/", arg);
	token = strtok(path, ":");

	while (token)
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
	free(arg);
	return (NULL);
}
