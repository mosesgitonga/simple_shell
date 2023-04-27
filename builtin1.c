#include "shell.h"

/**
 * _myhistory-hist displ.
 * @info:nstant function prototype.
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	list_t *current_node;

	for (current_node = info->history; current_node; current_node = current_node->next)
	{
		printf("%d %s\n", current_node->num, current_node->str);
	}
	return (0);
}

/**
 * unset_alias- set string
 * @info:paramStruct
 * @str:string alias
 *
 * Return:0
 */
int unset_alias(info_t *info, char *str)
{
	char *x = NULL, c;
	int ret;

	x = _strchr(str, '=');
	if (!x)
	{
		return (1);
	}

	c = *x;
	*x = '\0';
	ret = delete_node_at_index(&(info->alias),
							   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = c;

	return (ret);
}

/**
 * set_alias- string
 * @info:struct
 * @str:string alias
 *
*
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *x = NULL;

	x = _strchr(str, '=');
	if (!x)
	{
		return (1);
	}

	if (!*++x)
	{
		return (unset_alias(info, str));
	}

	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *x = NULL, *a = NULL;

	if (!node)
	{
		return (1);
	}

	x = _strchr(node->str, '=');

	for (a = node->str; a <= x; a++)
	{
		_putchar(*a);
	}

	_putchar('\'');
	_puts(x + 1);
	_puts("'\n");

	return (0);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int k = 0;
	char *z = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		for (node = info->alias; node; node = node->next)
		{
			print_alias(node);
		}

		return (0);
	}

	for (k = 1; info->argv[k]; k++)
	{
		z = _strchr(info->argv[k], '=');

		if (z)
		{
			set_alias(info, info->argv[k]);
		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[k], '='));
		}
	}

	return (0);
}
