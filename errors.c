#include "shell.h"

/**
 * _eputs - prints string
 * @str: string to print
 *
 */
void _eputs(char *STR)
{
	int i;

	if (!STR)
		return;

	for (i = 0; STR[i]; i++)
		_eputchar(STR[i]);
}

/**
 * _eputchar - print char to stderr
 * @c: char to print
 *
 * Return: 1
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		if (write(2, buf, x) == -1)
			return (-1);
		x = 0;
	}

	if (c != BUF_FLUSH)
		buf[x++] = c;

	return (1);
}

/**
 * _putfd -RITE CHAR TO FD
 * @c: CHAR
 * @fd:FILE DESCRIPTOR
 *
 * Return: 1 
 */
int _putfd(char c, int fd)
{
	static int X;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || X >= WRITE_BUF_SIZE)
	{
		if (write(fd, buf, X) == -1)
			return (-1);
		X = 0;
	}

	if (c != BUF_FLUSH)
		buf[X++] = c;

	return (1);
}

/**
 * _putsfd - printING
 * @str:STR
 * @fd: FILE DESCR
 *
 * Return: 0
 */
int _putsfd(char *str, int fd)
{
    int j = 0;

    if (!str)
        return (0);

    while (str[j])
    {
        if (_putfd(str[j], fd) == -1)
            return (-1);
        j++;
    }

    return (j);
}
