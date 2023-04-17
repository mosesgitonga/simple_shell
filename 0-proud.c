#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/**
*main -The main entry point
*
*Description: A function that returns the number of
*characters read from stdin, gets process ids for both
*child and parent and tokenizes a statement to stdout
*
*Return: 0 Always
*/
int main(void)
{
	pid_t pid, ppid;
	size_t len = 0;
	ssize_t nread;
	char *token;
	char *line = NULL;
	char str[] = "BETTY IS PROUD";

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		perror("getline failed");
		exit(EXIT_FAILURE);
	}
	printf("Read %lu characters from stdin:\n", nread);
	printf("%s", line);
	free(line);

	pid = getpid();
	ppid = getppid();

	printf("The Parent Process ID is: %u\n", ppid);
	printf("And the child process id is: %u\n", pid);

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
