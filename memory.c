#include "shell.h"

/**
 * bfree - freess
 * @ptr: ddress of the pointer to free
 *
 * Return: 1 
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
