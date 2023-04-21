#include "main.h"
/**
 * handle_path - handling the path using execvp()
 * Return: 0
 */
int handle_path(void)
{
	char *input, *token;
	size_t input_size = 0;
	ssize_t read;

	printf(":) ");
	while (read = getline(&input, &input_size, stdin) != -1)
	{
		char **argv;
		size_t argc = 0;
		pid_t pid;

		token = strtok(input, " \n");
		argv = malloc(sizeof(char *) * 80);
		while (token)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;
		pid = fork();
		if (pid == 0)
		{
			execvp(argv[0], argv);
			perror("./shell ");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
		}
		free(argv);
		printf(":) ");
	}
	free(input);
	return (0);
}
