#include "main.h"

#define MAX_ARGS 10

/**
*exit_shell - A function that implements the exit
*builtin that exits the shell
*
*Return: Void
*/
void exit_shell(void)
{
	char *args[MAX_ARGS] = {NULL};
	int i = 0;

	if (strcmp(args[i], "exit") == 0)
	{
		exit(0); /*successful termination*/
	}
}
