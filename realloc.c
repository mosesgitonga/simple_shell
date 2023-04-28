#include "shell.h"

/**
**_memset -A Function that fills memory with
*a constant byte
*@s: The pointer to the memory area
*@b: The byte to fill *s with
*@n: The amount of bytes to be filled
*Return: (s) a pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i; /*Loop Counter*/

	i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}

/**
* ffree - A Function that frees a string of strings
* @pp: The string of strings
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
	{
		return;
	}
	for (; *pp; ++pp)
	{
		free(*pp++);
	}
	free(a);
}

/**
* _realloc - A function that re-allocates 
*a block of memory
* @ptr: pointer to previous block
* @old_size: byte size of previous block
* @new_size: byte size of new block
*
* Return: pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	p = malloc(new_size);
	if (!p)
	{
		return (NULL);
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
