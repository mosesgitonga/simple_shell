#include "shell.h"

/**
 * _myenv -curr env
 * @info: Struct of info
 * Return:0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv-environ var
 * @info: Struct
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node;
	char *d;
	for (node = info->env; node; node = node->next)
	{
		d = starts_with(node->str, name);
		if (d && *d)
			return (d);
	}
	return (NULL);
}

/**
 * _mysetenv - Iniit env
 *         
 * @info: Struct
 *  Return:  0
 */
int _mysetenv(info_t *info)
{
	info->argc != 3 ? (_eputs("Incorrect number of arguements\n"), 1) : 0;
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -rm 
 * @info: Struct of potential arg
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int x;
	if (info->argc == 1)
		return (_eputs("Too few arguements.\n"), 1);
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list-poulates
 * @info:struct
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	size_t j;
	list_t *node = NULL;
	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}
