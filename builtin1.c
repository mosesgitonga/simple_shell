#include "shell.h"

/**
 * _myhistory - print history
 *
 * @info: Struct 
 * Return:  0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

int unset_alias(info_t *info, char *str)
{
        char *p = NULL, c = '\0';
        int ret;

        p = _strchr(str, '=');
        if (p == NULL) {
                return 1;
        }

        c = *p;
        *p = '\0';
        ret = delete_node_at_index(&(info->alias),
                get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
        *p = c;

        return ret;
}

/**
 * set_alias-sets an alias
 * @info:parameter struct
 * @str:string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p = _strchr(str, '=');
	if (!p)
		return (1);

	if (!*++p)
		return unset_alias(info, str);

	unset_alias(info, str);
	return add_node_end(&(info->alias), str, 0) == NULL ? 1 : 0;
}

/**
 * print_alias- an alias string
 * @node:alias node
 *
 * Return:0
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return 0;
	}

	return 1;
}

/**
 * _myalias-mimics
 * @info: Struct 
 * Return:0
 */
int _myalias(info_t *info)
{
	char *p = NULL;
	list_t *node = NULL;
	int i;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return 0;
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return 0;
}
