#include "shell.h"

/**
 * add_node - adds
 * @head: address
 * @str: string
 * @num: node
 *
 * Return: size of list
 */

/***************************************/
list_t *add_node(list_t **h, const char *string, int n)
{
	list_t *new_head;






	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));



	if (!new_head)
		return (NULL);
/****************************/


	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = n;


/****************************************************/


	if (string)
	{
		new_head->str = _strdup(string);


		if (!new_head->str)
		{
			free(new_head);



			return (NULL);





		}
	}
	new_head->next = *h;
	*h = new_head;




	return (new_head);

}

/**
 * add_node_end- adds node in list
 * @head: addr
 * @str: string
 * @num: num
 *
 * Return:list
 */
list_t *add_node_end(list_t **h, const char *s, int n)
{
	list_t *new_node, *node;


/*******************************************************/
	if (!h)
		return (NULL);

	node = *h;

/*************************************/
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));



/***********************************************************/
	new_node->num = n;
	if (s)
	{
		new_node->str = _strdup(s);
		if (!new_node->str)
		{
			free(new_node);




			return (NULL);
		}
	}


/***************************************************/


	if (node)
	{
		while (node->next)



			node = node->next;
		node->next = new_node;
	}


/****************************************************/
	else
		*h = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list



 * @h: pointer to first node
 *
 * Return: size of list
 */



size_t print_list_str(const list_t *b)
{


	size_t j = 0;

	while (b)
	{
		_puts(b->str ? b->str : "(nil)");


		_puts("\n");

/******/
		b = b->next;
		j++;



	}
	return (j);
}




/**
 * delete_node_at_index -index
 * @h:first node
 * @in: index
 *
 * Return: 
 */
int delete_node_at_index(list_t **h, unsigned int in)
{


	list_t *node, *prev;
	unsigned int i = 0;

	if (!h   || !*h)

		return (0);




	if (!in)
	{
		node = *h;


		*h = (*h)->next;

/********************************************************/


		free(node->str);
		free(node);




		return (1);
	}
	node = *h;




	while (node)
	{/***********************************************/
		if (i == in)
		{
			prev->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
/*********************************************/

		prev = node;
		node = node->next;


	}
	return (0);
}


/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
*
*
*
 *
 * Return: void
 */


void free_list(list_t **_ptr)
{



	list_t *node, *next_, *head;



	if (!_ptr || !*_ptr)



		return;

/***********************************************/
	head = *_ptr;


	node = head;




	while (node)
	{



		next_ = node->next;


		free(node->str);



		free(node);


		node = next_;
	}

/*******************************/
	_ptr = NULL;
}
