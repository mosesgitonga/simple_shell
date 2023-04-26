#include "shell.h"

/**
 *_eputs -str
 * @string: str 
*
 *
 * Return: VOID
 */
void _eputs(char *string)
{
	int i = 0;



	if (!string)
		

		return;


	while (string[i] != '\0')


	{
		_eputchar(string[i]);
		i++;
	}
}

/**
 * _eputchar - char c
 * @ch:charactertoprint
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */





int _eputchar(char ch)
{
	static int i;

	static char buf[WRITE_BUF_SIZE];






	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{




		write(2, buf, i);
		i = 0;

	}
	if (ch != BUF_FLUSH)

		buf[i++] = ch;
	return (1);
}

/**
 * _putfd -writes to fd
 * @ch: The character to print
 * @fdes:filedescriptor
 *
 * Return:1.
 */
int _putfd(char ch, int fdes)
{


	static int i;
	static char buf[WRITE_BUF_SIZE];



	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{



		write(fdes, buf, i);
		i = 0;
	}

	if (ch != BUF_FLUSH)


		buf[i++] = ch;

	return (1);
}

/**
 *_putsfd -input string
 * @tri: str
 * @fdes:filedescriptor
 *
 * Return: 0;
*
 */
int _putsfd(char *tri, int fdes)
{
	int i = 0;


	if (!tri)

		return (0);
	while (*tri)
	{



		i += _putfd(*tri++, fdes);

	}
	return (i);
}
