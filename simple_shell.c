#include "main.h"


/**
 * main - simple shell, command interpreter, loops to
 * display prompt, parse and execute simple commands
 * with arguments on interactive a non interactive mode.
 * @argc: variable
 * @argv: pointer
 * Return: if successful 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL, **args = NULL;

	shell_name = argv[0];
	do {
		line = read_line();

		if (check_for_builtins(&line))
		{
			free(line);
			continue;
		}

		args = tokenize_line(line);
		exec_line(args);
		free(args);
		free(line);
	} while (1);

	return (0);
}


/**
 * read_line - simple prompt "$" and read line from STDIN
 * sets terminal on interactive and non intereactive mode
 *
 * Return: buffer with the commands get from STDIN
 */
char *read_line(void)
{
	char *buffer = NULL;
	int tty = 1;
	size_t buffer_size = 0;

	counted++;
	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	fflush(stdin);

	tty == 1 ? write(STDOUT_FILENO, "$ ", 2) : tty;

	if (getline(&buffer, &buffer_size, stdin) == EOF)
	{
		if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}


/**
 * tokenize_line - function to split line arguments gets from STDIN
 *
 * @line: contains the imput get from STDIN
 *
 * Return: The tokenize string
 */
char **tokenize_line(char *line)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		free(tokens);
		exit(EXIT_FAILURE);
	}


	token = strtok(line, " \t\n");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;
	return (tokens);
}

/**
 * exec_line - function to execute the commands parser
 *
 * @args: double pointer that contains the parser commands
 *
 * Return:  0 success
 */
int exec_line(char **args)
{
	pid_t pid;
	int status;

	if (args[0] != NULL || args == NULL)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if (execve(get_path(args[0]), args, NULL) == -1)
			{
				__error(shell_name, counted, args[0]);
				_free(args);
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
