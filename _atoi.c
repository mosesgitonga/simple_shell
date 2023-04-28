#include "shell.h"

/**
 * interactive-shell is interactive mode
 * @info:struct address
 *
 * Return:1 
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim-checker for delimiter
 * @c:check
 * @delim:delimiter string
 * Return: 1 
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
 * _isalpha-alphabetic character
 * @c:character to input
 * Return:1
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi-atoi
 * @s:string to be converted
 * Return:0
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] && flag != 2; i++)
	{
		sign = (s[i] == '-') ? -1 : sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = (result * 10) + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	output = (sign == -1) ? -result : result;

	return (output);
}
