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
	int i, num_args;

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
		input[strcspn(input, "\n")] = '\0';
		
		num_args = 0;
		token = strtok(input, " ");
		
		while (token != NULL)
		{
			num_args++;
			token = strtok(NULL, " ");
		}
		args = malloc(sizeof(char *) * (num_args + 1));
		if (args == NULL)
		{
			perror("malloc");
			exit(1);
		}
		token = strtok(input, " ");
		i = 0;
		
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[num_args] = NULL;
		/*Execute command*/
		pid = fork();
		
		if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("execve");
			exit(1);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
			exit(1);
		}
		free(args);
	}
	return (0);
}
