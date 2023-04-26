#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>






#define PROMPT "#cisfun$ "

void execute(char *commandd) 
{
    char *argv[] = {commandd, NULL};

    if (execve(commandd, argv, NULL) == -1) 
    {
        perror("./shell: ");
    }
}

int main(void) {
    char *input = NULL;
    size_t input_size = 0;
    pid_t pid;
    int status;

    while (1) 
    {
        printf(PROMPT);
        if (getline(&input, &input_size, stdin) == -1) 
	{

            printf("\n");
            break;
        }
	input[strcspn(input, "\n")] = '\0'; 

        pid = fork();
        if (pid == -1) 
	{
            perror("Error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) 
	{
            execute(input);
            exit(EXIT_SUCCESS);
        } 
	else 
	{
            waitpid(pid, &status, 0);
        }
    }

    free(input);
    return (EXIT_SUCCESS);
}

