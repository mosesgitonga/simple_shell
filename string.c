#include "shell.h"

/**
* _strlen - A Function that returns the length of
*a string
*
*@s: Thee string
*
*Return: string length
*/
int _strlen(char *s)
{
	int len = 0; /*Loop Counter*/

	if (!s)
		return (0);

	while (*s++)
		len++;
	return (len);
}

/**
* _strcmp -A function that  performs lexicogarphic
*comparison of two strings.
* @s1: The first string
* @s2: the second string
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}

/**
* starts_with - A function that checks if needl
*starts with haystack
* @haystack:The haystack
* @needle: The needle
*
*Return: address of next character of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}

/**
* _strcat - A function that concatenates two strings
* @dest: The destination string
* @src: The source string
*
* Return: A pointer to concatenated string(dest)
*/
char *_strcat(char *dest, char *src)
{
	char *concat_str = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (concat_str);
}
