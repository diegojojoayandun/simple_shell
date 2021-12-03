#include "main.h"


/**
 * main - simple shell, display prompt, parse and execute
 * simple commands, mode interactive a non interactive
 * Return: int value
 */
int main(void)
{
	char *line = NULL, **args = NULL;

	welcomeScreen();

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
 * read_line - simple prompt
 *
 * Return: int value
 */
char *read_line(void)
{
	char *buffer = NULL;
	int tty = 1;
	size_t buffer_size = 0;

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
 * tokenize_line - function to split line arguments
 *
 * @line: char pointer
 * Return: a char** with the tokenize string
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
 * @args: double pointer that contains the parser commands
 * Return:  a  int value
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
				perror("error");
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

/**
 * welcomeScreen - welcome screen of our shell
 */
void welcomeScreen(){
        printf("\n\t============================================\n");
        printf("\t               Simple C Shell\n");
        printf("\t--------------------------------------------\n");
        printf("\t           C16 Holberton School Cali\n");
	printf("\t--------------------------------------------\n");
        printf("\t           	     2021\n");
        printf("\t============================================\n");
        printf("\n\n");
}