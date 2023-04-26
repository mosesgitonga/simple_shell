#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define DELIMITER "\t\r\n\a"
int main(int argc, char *argv[])
{
	char *command, *arguments[BUFFER_SIZE];
	char buffer[BUFFER_SIZE]; /*Store user input*/
	char *path = getenv("PATH");
	char *path_token;
	char command_path[BUFFER_SIZE];
	int status = 1, i = 0, found = 0;
	pid_t pid;
	(void)argc;
	(void)argv;

	while (status)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(buffer, BUFFER_SIZE, stdin))
		{
			break;
		}
		command = strtok(buffer, DELIMITER);

		while (command != NULL)
		{
			arguments[i] = command;
			command = strtok(NULL, DELIMITER);
			i++;
		}
		arguments[i] = NULL;

		if (strcmp(arguments[0], "exit") == 0)
		{
			exit(0); /*succesful exit*/
		}
		path_token = strtok(path, ":");

		while (path_token != NULL)
		{
			snprintf(command_path, BUFFER_SIZE, "%s/%s", path_token, arguments[0]);
			if (access(command_path, X_OK) == 0)
			{
				found = 1;
				pid = fork();
				if (pid == 0)
				{
					execvp(command_path, arguments);
				}
				else
				{
					waitpid(pid, NULL, 0);
				}
				break;
			}
			path_token = strtok(NULL, ":");
		}
		if (!found)
		{
			printf("Command not found: %s\n", arguments[0]);
		}
	}
	return (0);
}
