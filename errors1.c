#include "shell.h"

/**
 * _erratoi -str to int
 * @s:str
 * Return: 0 
 */
int _erratoi(char *s)
{
    char *b = NULL;
    int i;
    unsigned long int result = 0;

    if (*b == '+')
        b++;

    for (i = 0; s[i]; i++)
    {
        if (b[i] >= '0' && b[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }

    return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: void
 */
void print_error(info_t *info, char *estr)
{

    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");


    _eputs(info->argv[0]);
    _eputs(": ");

    _eputs(estr);
}

/**
 * print_d - func 
 * @input:input
 * @fd:filedes
 *
 * Return: 0
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int n, count = 0;
    unsigned int _abs_, current;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;

    current = _abs_;
    for (n = 1000000000; n > 1; n /= 10)
    {
        if (_abs_ / n)
        {
            __putchar('0' + current / n);
            count++;
        }

        current %= n;
    }

    __putchar('0' + current);
    count++;

    return (count);
}

/**
 * convert_number - itoa clone
 * @num: num
 * @base:base
 * @flags:flags
 *
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
    static char *arr;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }

    arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = arr[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return (ptr);
}
/**
 * remove_comments -function replaces 
 * @buf: addr
 *
*
 * Return: NULL
 */
void remove_comments(char *buf)
{
    int z;

    for (z = 0; buf[z]; z++)
        (buf[z] == '#' && (!z || buf[z - 1] == ' ')) ? buf[z] = '\0' : 0;
}
