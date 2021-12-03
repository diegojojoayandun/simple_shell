#include "main.h"

void __error(char *arg, int size, char *command)
{
	printf("%s", arg);
	printf(": ");
	printf("%d", size);
	printf(": ");
	printf("%s", command);
	printf(": not found");

}