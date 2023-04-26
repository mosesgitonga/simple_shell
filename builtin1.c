#include "shell.h"

/**
 * _myhistory - is a display
 * @info: Struct
 *  Return:  0
 */
int _myhistory(info_t *infomation)
{


	print_list(infomation->history);


	return (0);
}

/**
 * unset_alias -alias ais set
 * @info: parameter struc
 * @str:string alkias
*
*
 *
 * Return: 0
 */
int unset_alias(info_t *infomation, char *string)


{

	char *p, c;

	int returnn;




	p = _strchr(string, '=');
	if (!p)
		return (1);


	c = *p;
	*p = 0;


	returnn = delete_node_at_index(&(infomation->alias),
		get_node_index(infomation->alias, node_starts_with(infomation->alias, string, -1)));
	*p = c;
	return (returnn);





}

/**
 * set_alias - alias
 * @info: palameter
 * @str: string

*
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *infomation, char *string)
{



	char *p;

	p = _strchr(string, '=');
	if (!p)


		return (1);
	if (!*++p)
	{
		return (unset_alias(infomation, string));
	}


	unset_alias(infomation, string);
	return (add_node_end(&(infomation->alias), string, 0) == NULL);


}

/**
 * print_alias - to print the alias
*
 * @node: node alias
 *
 * Return: 0;
 */





int print_alias(list_t *node)

{
	char *c = NULL, *b = NULL;

	if (node)


	{

		b = _strchr(node->str, '=');
		for (b = node->str; b <= c; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(c + 1);
		_puts("'\n");
		return (0);


	}
	return (1);

}

/**
 * _myalias - alias
 * @info: arguments in structure
 *  Return:0
 */

int _myalias(info_t *infom)


{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infom->argc == 1)
	{
		node = infom->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}


		return (0);

	}
	for (i = 1; infom->argv[i]; i++)
	{
		p = _strchr(infom->argv[i], '=');
		if (p)
			set_alias(infom, infom->argv[i]);
		else
		{
			print_alias(node_starts_with(infom->alias, infom->argv[i], '='));
		}
	}



	return (0);
}
