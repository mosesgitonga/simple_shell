#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * display - to display thr shell prompt
 * which also executes commands with path specified
 * Return: 0
 */

int display()
{
	char *input, *token;
	size_t input_size = 0;
	ssize_t read;

	printf("#cisfun$ ");
	while ((read = getline(&input, &input_size, stdin)) != -1)
	{
		char **argv = malloc(sizeof(char) * 80);
		size_t argc = 0;
		pid_t pid;

		token = strtok(input, " \n");
		while (token)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("./shell");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork error");
		}
		printf("#cisfun$ ");
		free(argv);
	}
	free(input);
	return (0);
}
