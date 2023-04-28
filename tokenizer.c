#include "shell.h"

/**
* **strtow - A function that splits a string into
*words (tokens)
* @str: The input string to be tokenized
* @d: The delimeter string to dictate tokenization
* Return: A pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	i = 0;
	j = 0;
	k = 0;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
	{
		d = " ";
	}
	while (str[i] != '\0')
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
		{
			numwords++;
		}
		i++;
	}

	if (numwords == 0)
	{
		return (NULL);
	}
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;

		for (; !is_delim(str[i + k], d) && str[i + k]; k++)
		{
			/*Empty Body*/
		}
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		m = 0;
		while (m < k)
		{
			s[j][m] = str[i++];
			m++;
		}
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
* **strtow2 -A function that splits a string into words
*
* @str: The input string to tokenize
* @d: The delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != d && str[i + 1] == d) || (str[i] != d && !str[i + 1]) || str[i + 1] == d)
		{
			numwords++;
		}
		i++;
	}
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		for (; str[i + k] != d && str[i + k] && str[i + k] != d; k++)
		{
			/* Empty Body */
		}
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

