#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct containing shell information
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	int i;
	
	for (i = 0; delim[i]; i++)
		if (delim[i] == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if character is an alphabetic character
 * @c: the character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int sign = (*s == '-') ? -1 : 1, i;
	unsigned int result = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
		}
		else if (result > 0)
		{
			break;
		}
	}

	return ((int)(sign * result));
}
