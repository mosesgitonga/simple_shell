#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
/**
 * simple_shell - a function  to create a simple shell prompt
 * @ac: argument count
 * @argv: argumrent vector
 *Return: 0
 */
int simple_shell(int ac, char **argv)
{
	char *input = NULL;
	size_t input_len = 0;
	ssize_t read_len;
	char *token;
	char **args;
	pid_t pid;

	(void)ac;
	(void)argv;

	while (1) 
	{
		printf("cisfun$ ");
		read_len = getline(&input, &input_len, stdin);
		if (read_len == -1)
		{
			printf("\n");
			exit(0);
			free(input);
		}
		input[strcspn(input, "\n")] = 0;
		args = malloc(sizeof(char *) * 64);
		token = strtok(input, " \n");
		int i = 0;
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;

		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, NULL);
			printf("Error: command not found.\n");
			exit(1);
			free(args);
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
		free(args);
	}
	return (0);
}
