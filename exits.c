#include "shell.h"

/**
 * _strncpy-cp a str
 * @dest:desTInation
 * @src:source of string
 * @n:num of chars
 * Return: str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	for (i = 0; i < n - 1 && src[i]; i++)
	
		dest[i] = src[i];
	for (j = i; j < n; j++)
		dest[j] = '\0';
	return (s);
}

/**
 * _strncat -concat str
 * @dest:1st str
 * @src:2nd str
 * @n: mem
 * Return:str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;



	while (dest[i])
		i++;
	for (j = 0; src[j] && j < n; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (s);
}

/**
 * _strchr -string char
 * @s:string
 * @c: char
 * Return:pointer
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		

			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

