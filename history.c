#include "shell.h"

/**
 * get_history_file-history -  getting history
*
 * @info:struct
 *
 * Return:allocated string containg history file
 */

char *get_history_file(info_t *content)
{
	char *tek, *nun;

	nun = _getenv(content, "HOME=");
	if (!nun)
		return (NULL);




	tek = malloc(sizeof(char) * (_strlen(nun) + _strlen(HIST_FILE) + 2));

/**/
	if (!tek)
		return (NULL);
	tek[0] = 0;







	_strcpy(tek, nun);


	_strcat(tek, "/");



	/**/

	_strcat(tek, HIST_FILE);
	return (tek);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @content: the parameter struct
 *
 * Return: 1 on success, else -1
 */

/*nnnn8*/
int write_history(info_t *content)
{
	ssize_t dest;
	char *filename = get_history_file(content);

/***/

	list_t *node = NULL;

	if (!filename)
		return (-1);

	dest = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
/**/


	if (dest == -1)
		return (-1);
	for (node = content->history; node; node = node->next)
	{
		_putsfd(node->str, dest);


		_putfd('\n', dest);
/**/

	}
	_putfd(BUF_FLUSH, dest);
	close(dest);

/**/
	return (1);
}

/**
 * read_history - reads 
 * @cont: struct
 *
 *
 * Return:0
 */
int read_history(info_t *cont)
{
	int i, last = 0, linecount = 0;

/**/
	ssize_t fd, len, fsize = 0;

	struct stat st;

	char *buf = NULL, *filename = get_history_file(cont);




/*NJJJNJUNJUNJ*MMKJ*/
	if (!filename)
		return (0);




	fd = open(filename, O_RDONLY);




	free(filename);
	if (fd == -1)


		return (0);


/***************************************************************************************************************************************/



	if (!fstat(fd, &st))
		fsize = st.st_size;

	if (fsize < 2)

		return (0);

	buf = malloc(sizeof(char) * (fsize + 1));







	if (!buf)
		return (0);


	len = read(fd, buf, fsize);
	buf[fsize] = 0;

	if (len <= 0)


		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(cont, buf + last, linecount++);
			last = i + 1;
		}




	if (last != i)


		build_history_list(cont, buf + last, linecount++);
	free(buf);

	cont->histcount = linecount;
	while (cont->histcount-- >= HIST_MAX)
		delete_node_at_index(&(cont->history), 0);


	renumber_history(cont);

	return (cont->histcount);
}

/**
 * build_history_list -DJHJD
*
 * @cont: STRUCTYURE
 * @buff: BUFF
 * @linecount: HISTORY COUNT
 *
*
 * Return: 0
 */
int build_history_list(info_t *cont, char *buff, int linecount)
{


	list_t *node = NULL;

/*JBHGVVKK8*/









	if (cont->history)


		node = cont->history;




	add_node_end(&node, buff, linecount);

/***/




	if (!cont->history)

/*******************************************************************************/

/***********************************HHHHHHHHHHHHHKKNJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ*/


		cont->history = node;
	return (0);
}

/**
 * renumber_history - nuumbering hist
*
 * @cont: info
 *
 * Return: 0
 */
/********************************************************/
int renumber_history(info_t *cont)
{
	list_t *node = cont->history;
	int i = 0;
/*********************************************************/
	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (cont->histcount = i);
}
