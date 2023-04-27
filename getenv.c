#include "shell.h"

/**
 * get_environ - returns string
 * @info:struct
 * Return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}



	return (info->environ);
}
/**************************/

/**
 * _unsetenv-remove
 * @info: Struct
 * @var:string
 * Return:1;
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i;
	char *p;

	if (!node || !var)
		return (0);

	for (i = 0; node; i++, node = node->next)
	{
	
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
	}
	return (info->env_changed);
}

/**
 * _setenv -init
 * @info: Struct
 * @var: string
 * @value:value
 * Return:0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf;
	list_t *node;
	char *p;
	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
    	if (!buf)
            	return (1);
    	_strcpy(buf, var);
    	_strcat(buf, "=");
    	_strcat(buf, value);
    	node = info->env;
    	for (; node; node = node->next)
    	{
            	p = starts_with(node->str, var);
            	if (p && *p == '=')
            	{
                    	free(node->str);
                    	node->str = buf;
                    	info->env_changed = 1;
                    	free(buf);
                    	return (0);
            	}
    	}
    	add_node_end(&(info->env), buf, 0);
    	info->env_changed = 1;
    	return (0);
}
