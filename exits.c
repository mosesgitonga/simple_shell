#include "shell.h"

/**
 * _strncpy- string copy
 * @dest:destination
 * @src:source
 * @n:num of chars
 *
 * Return: concat str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	if (i < n)
		for (; i < n; i++)
			dest[i] = '\0';

	return (dest);
}

/**
 * _strncat-concat str
 * @dest:1st str
 * @src:2nd str
 * @n:num of bytes
 *
 * Return:str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0' && j < n; j++)
		dest[i + j] = src[j];

	if (j < n)
		dest[i + j] = '\0';

	return (dest);
}

/**
 * _strchr-locator
 * @s:string
 * @c: char we are looking for
 *
 * Return: pointer
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

