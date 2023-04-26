#include "shell.h"

/**
 * interactive - thois fuction return truee
 * @info: structure addrress
 *
 * Return: 1 or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - delimiter
 * @c: char
 * @delim:delimiter string
 * Return: 1
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)


			return (1);
	return (0);
}

/**
 *_isalpha - fucttiion to check if alpha
 *@c: input
 *Return: 1 or 0
 */

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else



		return (0);
}



/**
 *_atoi -string to an integer
 *@str: thee string to be converted
 *Return:0
 */

int _atoi(char *str)
{
	int i, sign = 1, flag = 0, num = 0;
	unsigned int result = 0;

	for (i = 0;  str[i] != '\0' && flag != 2; i++)
	{


		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')


		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		num = -result;
	else


		num = result;

	return (num);
}
