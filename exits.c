#include "shell.h"

/**
 **_strncpy - strcpy
 *@final: dest
 *@begin: string source
 *@n: char amount
 *Return: string
 */

char *_strncpy(char *final, char *begin, int n)
{


	int i, j;


	char *s = final;

	i = 0;



	while (begin[i] != '\0' && i < n - 1)
	{


		final[i] = begin[i];
		i++;
	}
	if (i < n)



	{
		j = i;


		while (j < n)




		{
			final[j] = '\0';

			j++;
		}


	}
	return (s);
}

/**
 **_strncat - string
 *@dest: 1st  string
 *@src:2nd string
 *@n: memory
 *Return: char
 */
char *_strncat(char *final, char *begin, int n)

{
	int i, j;

	char *s = final;

	i = 0;


	j = 0;

	while (final[i] != '\0')


		i++;



	while (begin[j] != '\0' && j < n)
	{



		final[i] = begin[j];

		i++;


		j++;
	}


	if (j < n)
		final[i] = '\0';



	return (s);
}

/**
 **_strchr -string
*
 *@str:string to be parsed
 *@ch:character to look for
 *Return:s a pointer 
 */
char *_strchr(char *str, char ch)
{

	do 
	

	{
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');



	return (NULL);
}
