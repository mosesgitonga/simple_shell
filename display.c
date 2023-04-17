#include "main.h"
/**
 * display - to display thr shell prompt
 * which also executes commands with path specified
 * Return: 0
 */

int display(void)
{
	char *input, *token;
	size_t input_size = 0;
	ssize_t read;

	printf("./shell$ ");
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
			execve(argv[0], argv, NULL);
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
		printf("./shell$ ");
		free(argv);
	}
	free(input);
	return (0);
}
