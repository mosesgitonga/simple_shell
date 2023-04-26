#include "shell.h"

/**
 * _erratoi -string to an integer
 * @m:string
 * Return: 0 
 */

int _erratoi(char *m)
{
	int i = 0;




	unsigned long int result = 0;

	if (*m == '+')
		m++;  

	for (i = 0;  m[i] != '\0'; i++)
	{



		if (m[i] >= '0' && m[i] <= '9')
		{
			result *= 10;
			result += (m[i] - '0');


			if (result > INT_MAX)
				return (-1);
		}
	

	else
			return (-1);
	}
	return (result);
}

/**
 * print_error - errror mesg
 * @info: the parameter
 * @estr:  error type
 * Return: 0
 */
void print_error(info_t *infomat, char *str)
{


	_eputs(infomat->fname);

	_eputs(": ");
	print_d(infomat->line_count, STDERR_FILENO);

	_eputs(": ");
	_eputs(infomat->argv[0]);


	_eputs(": ");

\

	_eputs(str);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @filedes: filedes
 *
 * Return: 0
 */
int print_d(int input, int filedes)
{



	int (*___putchar)(char) = _putchar;
	int i, count = 0;


	unsigned int absolute, current;



	if (filedes == STDERR_FILENO)


		___putchar = _eputchar;
	if (input < 0)


	{


		absolute = -input;


		___putchar('-');
		count++;
	}



	else
		absolute = input;


	current = absolute;
	for (i = 1000000000; i > 1; i /= 10)


	{


		if (absolute / i)

		{

			___putchar('0' + current / i);

			count++;

		}

		current %= i;

	}

	___putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - to itoa
 * @num: num
 * @base: the base
 * @flag: flags
 *
 * Return: string
 */
char *convert_number(long int dig, int base, int flag)
{
	static char *arr;

	static char buffer[50];


	char sign = 0;
	char *ptr;


	unsigned long n = dig;


	if (!(flag & CONVERT_UNSIGNED) && dig < 0)
	{
		n = -dig;
		sign = '-';




	}
	arr = flag &   CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";



	ptr = &buffer[49] ;

	*ptr = '\0';


	do	{
		*--ptr = arr[n % base];
		n /= base;


	} 


	while (n != 0);

	if (sign)


		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replacer
 * @ubuf: addressss
 *
*
*
 * Return:  0;
 */



void remove_comments(char *ubuf)

{
	int i;



	for (i = 0; ubuf[i] != '\0'; i++)



		if (ubuf[i] == '#' && (!i || ubuf[i - 1] == ' '))
		{
	


		ubuf[i] = '\0';
			break;

		}
}
