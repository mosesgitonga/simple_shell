#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *args[] = { NULL };
    int status;
	


	while (1) 
	{
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) 
	{
            break;  
        }

        command[strcspn(command, "\n")] = '\0'; 

        if (strcmp(command, "exit") == 0) 
	{
            break;
        }

        pid_t pid = fork();

        if (pid == -1) 
	{
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) 
	{
            execve(command, args, NULL);
            perror("./shell"); 

            exit(EXIT_FAILURE);
        }

        wait(&status);
    }

    return 0;
}

