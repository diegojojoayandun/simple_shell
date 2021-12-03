#include "main.h"

/**
 * _free - free memory allocation
 *@ptr: double pointer
 * Return: void
 */
void _free(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		++i;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);

	free(ptr);
}
