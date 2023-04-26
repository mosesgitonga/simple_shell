#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
*simple_shell - A function that builds a simple CLI
*@ac: count
*@argv: argument vector
*
*Return: 0 always successful
*/
int simple_shell(int ac, char **argv)
{
	char *input;
	size_t input_len = 0;
	ssize_t read_len;
	char *token;
	char **args;
	pid_t pid;
	(void)ac;
	(void)argv;

	while (1) /*Infinite loop*/
	{
		/*print a prompt*/
		printf("cisfun$");
		/*Read input*/
		read_len = getline(&input, &input_len, stdin);
		if  (read_len == -1)
		{
			printf("\n");
			exit(0);
			free(input);
		}
		/*remove \n from the input*/
		input[strcspn(input, "\n")] = 0;

		token = strtok(input, " ");
		
		if (token == NULL)
		{
			continue;
		}
		/*Execute command*/
		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, NULL);
			printf("Error: command not found.\n");
			exit(1);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			printf("Error: fork failed");
			exit(1);
		}
	}
	return (0);
}
