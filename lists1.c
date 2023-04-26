#include "shell.h"
/*********************/
/**
 * list_len-hhhlist
 * @h:first node
 *
*hvbhj
 * Return:list
 */

/*******************************************/
size_t list_len(const list_t *p)
{
	size_t j = 0;

/*************************************/

	while (p)
	{
	
/*****/

		p = p->next;
		j++;

/**********/

	}
	return (j);


}

/**
 * list_to_strings - Returns an arr
 * @head: first node
 *
 * Return: strings
 */
char **list_to_strings(list_t *h)
{


/************/
	list_t *node  =   h;
	size_t i =    list_len(h), j;
/***********************************************/
	char **st;
	char *str;







/********************************/

	if (!h   || !i)
		return (NULL);
	st = malloc(sizeof(char *) * (i + 1));





	if (!st)
		return (NULL);
	for (i = 0; node; node = node->next, i++)




/******************************/
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{













			for (j = 0; j < i; j++)
				


				free(st[j]);
	
/*********************************************************/


			free(st);
			return (NULL);




/********/
		}






		str = _strcpy(str, node->str);






/**/

		st[i] = str;
	}






	st[i] = NULL;



/*dfghjkgygyugcgfcfcxxfxfcfcfxds*/
	return (st);
}




/**
 * print_list-list_tnm linked list
 * @h: node
 *
 * Return: size list
 */
size_t print_list(const list_t *l)

/***/

{
	size_t i = 0;

	while (l)




	{
		_puts(convert_number(l->num, 10, 0));
	/*****/


		_putchar(':');
		_putchar(' ');
/***********************************************************/


		_puts(l->str ? l->str : "(nil)");
		_puts("\n");

/*****************************************************/

		l = l->next;
		i++;

	}

/*************************************************/
	return (i);
}

/**
 * node_starts_with - Retunwhose string starts with prefix
 * @node:head
 * @prefix:str
 * @c:next
 *
 * Return: match
 */

/**HGGGGLKDD*/
list_t *node_starts_with(list_t *boo, char *prefix, char c)
{
	char *x = NULL;


/**/
	while (boo)

/*****************************************************/

	{
		x = starts_with(boo->str, prefix);






/***/

		if (x && ((c == -1) || (*x == c)))
/***/

			return (boo);
		boo = boo->next;
	}

	return (NULL);
}

/**
 * get_node_index-index of a node
 * @head:head
*
***
 * @node: node
 *
 * Return: -1
 */



ssize_t get_node_index(list_t *h, list_t *n)




{


	size_t i = 0;

	/************************************/
	while (h)


/**/
	{
		if (h == n)
			return (i);






		h = h->next;


		i++;
	}


/**/
	return (-1);
}
