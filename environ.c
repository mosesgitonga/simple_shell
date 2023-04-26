#include "shell.h"




/**
 * _myenv - printing env
 * @infoma: Structure 
 * Return: 0
 */
int _myenv(info_t *infoma)
{


	print_list_str(infoma->env);


	return (0);


}

/**
 * _getenv - val
 * @info:struct
 * @itsname:vat
*
*
 *
 * Return: char
 */
char *_getenv(info_t *infom, const char *itsname)


{
	list_t *node = infom->env;
	char *k;




	while (node)
	{
		k = starts_with(node->str, itsname);



		if (k && *k)


			return (k);
		node = node->next;

	}
	return (NULL);
}

/**
 * _mysetenv -mysentenv
 * @infom: Structure arg
 *  Return: 0
 */
int _mysetenv(info_t *infom)
{


	if (infom->argc != 3)
	{


		_eputs("Incorrect number of arguements\n");


		return (1);

	}
	if (_setenv(infom, infom->argv[1], infom->argv[2]))
		return (0);

	return (1);
}

/**
 * _myunsetenv - rem env
 * @infomat: Structo poten args
 *  Return: 0
 */

int _myunsetenv(info_t *infomat)


{
	int i;

	if (infomat->argc == 1)
	{
		_eputs("Too few arguements.\n");


		return (1);
	}
	for (i = 1; i <= infomat->argc; i++)
		_unsetenv(infomat, infomat->argv[i]);

	return (0);


}

/**
 * populate_env_list - linked listi
 * @infomax: Stuct of poten arggs
 * Return: 0
 */
int populate_env_list(info_t *infomax)
{



	list_t *node = NULL;
	size_t i;




	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	infomax->env = node;


	return (0);
}
