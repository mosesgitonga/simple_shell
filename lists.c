#include "shell.h"

/**
<<<<<<< HEAD
* add_node - adds a node to the start of the list
* @head: address of pointer to head node
* @str: str field of node
* @num: node index used by history
*
* Return: size of list
*/
=======
 * add_node - addd node sttart oof llist
 * @head: addr of node
 * @str: str field of node
 * @num:used by history
 *
 * Return: size of list
 */
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
	{
		return (NULL);
	}
	new_head = malloc(sizeof(list_t));
	if (!new_head)
	{
		return (NULL);
	}
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	new_head->str = str ? _strdup(str) : NULL;
	if (!new_head->str && str)
	{
		free(new_head);
		return (NULL);
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
<<<<<<< HEAD
* add_node_end - A function that adds a node
* to the end of the list
* @head: address of pointer to head node
* @str: str field of node
* @num: node index used by history
*
* Return: size of list
*/
=======
 * add_node_end-adds node
 * @head: addr
 * @str: str
 * @num:node
 *
 * Return:siize
 */
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
	{
		return (NULL);
	}
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	if (!new_node->str && str)
	{
<<<<<<< HEAD
		new_node->str = _strdup(str);

		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
=======
		free(new_node);
		return (NULL);
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
	}
	if (node)
	{
		for (; node->next; node = node->next)
			;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
<<<<<<< HEAD
* print_list_str - prints only the str element of 
* a list_t linked list
* @h: pointer to first node
*
* Return: size of list
*/
=======
 * print_list_str-prints string
 * @h:pointer first node
 *
 * Return:list size
 */
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
size_t print_list_str(const list_t *h)
{
	size_t i;

	for (i = 0; h; i++, h = h->next)
		_puts(h->str ? h->str : "(nil)"), _puts("\n");

	return (i);
}

/**
<<<<<<< HEAD
* delete_node_at_index - A Function that deletes
* a node at a specified index
* @head: address of pointer to first node
* @index: index of node to delete
*
* Return: 1 on success, 0 on failure
*/
=======
 * delete_node_at_index-del nodes
 * @head: addr of first node
 * @index: index 
 *
 * Return:1
 */
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	for (i = 0, node = *head; node; i++, node = node->next)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		prev_node = node;
	}
	return (0);
}
/**
<<<<<<< HEAD
* free_list - A functin that  frees all
* nodes of a list
* @head_ptr: address of pointer to head node
*
* Return: void
*/
=======
 * free_list-frees list
 * @head_ptr: addr of ptr node
 *
 * Return: void
 */
>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
	{
		return;
<<<<<<< HEAD
	}
=======

>>>>>>> d8475d5e9d58efe967bf73b4014c9d6b255d20e3
	head = *head_ptr;
	for (node = head; node; node = next_node)
	{
		next_node = node->next;
		free(node->str), free(node);
	}

	*head_ptr = NULL;
}
