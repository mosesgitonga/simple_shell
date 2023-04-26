#include "shell.h"

/**
 * clear_info -to initilise
 * @cont: structure addr
 */
void clear_info(info_t *cont)
{
	cont->arg = NULL;



	cont->argv = NULL;

	cont->path = NULL;


	cont->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @cont: struct address

 * @argv: argument vector
 */
void set_info(info_t *cont, char **argv)
{
	int i = 0;



	cont->fname = argv[0];
	if (cont->arg)
	{



		cont->argv    = strtow(cont->arg, " \t");

		if (!cont->argv)


		{



			cont->argv = malloc(sizeof(char *) * 2);
			if (cont->argv)


			{
				cont->argv[0] = _strdup(cont->arg);


				cont->argv[1] = NULL;
			}



		}
		for (i = 0; cont->argv && cont->argv[i]; i++)
			;
		cont->argc = i;

	

	replace_alias(cont);
		replace_vars(cont);
	}
}

/**
 * free_info -frees nfom
 * @nfom: structure
 * @b: true 
 */
void free_info(info_t *nfom, int b)

{

	ffree(nfom->argv);



	nfom->argv = NULL;
	nfom->path = NULL;
	if (b)
	{
		if (!nfom->cmd_buf)
			free(nfom->arg);

		if (nfom->env)

			free_list(&(nfom->env));

		if (nfom->history)

			free_list(&(nfom->history));

		if (nfom->alias)

			free_list(&(nfom->alias));

		ffree(nfom->environ);
			nfom->environ = NULL;


		bfree((void **)nfom->cmd_buf);
		if (nfom->readfd > 2)

			close(nfom->readfd);
		_putchar(BUF_FLUSH);


	}
}
