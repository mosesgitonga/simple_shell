#include "shell.h"

/**
 * get_environ - string
 * @cont: Struc
 * Return:0


 */
char **get_environ(info_t *cont)
{


	if (!cont->environ || cont->env_changed)
	{
		cont->environ = list_to_strings(cont->env);

/* ------------------------------------------------------------------------------------*/



		cont->env_changed = 0;
	}

/*======================================================================================*/

	return (cont->environ);
}

/**
 * _unsetenv - env
 * @cont: info
 * @alp: the string env var property
 *Return: 0;
 */
int _unsetenv(info_t *cont, char *alp)
{


	list_t *node = cont->env;
	size_t i = 0;


	char *p;

	if (!node || !alp)


		return (0);

	while (node)


	{
		p = starts_with(node->str, alp);


		if (p && *p == '=')
		{
			cont->env_changed = delete_node_at_index(&(cont->env), i);


			i = 0;
			node = cont->env;


			continue;
		}


		node = node->next;
		i++;
	}

	return (cont->env_changed);
}

/**
 * _setenv - env
 * @cont: Struc
 * @alp: var
 * @dig:value
 *  Return: 0
 */


int _setenv(info_t *cont, char *alp, char *dig)
{
	char *buf = NULL;

	list_t *node;
	char *p;


	if (!alp || !dig)
	

		return (0);

	
	buf = malloc(_strlen(alp) + _strlen(dig) + 2);
	

	if (!buf)
		return (1);
	
	_strcpy(buf, alp);
	_strcat(buf, "=");
	_strcat(buf, dig);
		

	node = cont->env;
	
	while (node)
	{
		p = starts_with(node->str, alp);
	

		if (p && *p == '=')
		{
			free(node->str);
	

			node->str = buf;
			cont->env_changed = 1;
			return (0);
		}
	

		node = node->next;
	

	}
	
	add_node_end(&(cont->env), buf, 0);
	free(buf);
	

	cont->env_changed = 1;
	return (0);
}
