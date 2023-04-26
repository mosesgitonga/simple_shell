#include "main.h"
#define MAX_COMMAND 4096

/**
 * simple_shell - a function to create a simple shell prompt
 * @av: arg vector
 * @env:this are enviroment variables
 * Return: void
 */
void simple_shell(char **av, char **env)
{
        char *input = NULL;
        size_t n = 0;
        ssize_t numChar;
        char *argv[MAX_COMMAND];
        pid_t pid;
        
	int status;


        while (1)
        {
                if (isatty(STDIN_FILENO))
                        printf("cisfun$ ");
                numChar = getline(&input, &n, stdin);
                if (numChar == -1)
                {
                        free(input);
                        exit(EXIT_FAILURE);
                }
                int i = 0;
                while (input[i])
                {
                        if (input[i] == '\n')
                                input[i] = 0;
                        i++;
                }
                argv[0] = input;
                pid = fork();
                if (pid == -1)
                {
                        free(input);
                        exit(EXIT_FAILURE);
                }
                if (pid == 0)
                {
                        if (execve(argv[0], argv, env) == -1)
                        {
                                printf("%s: No such file or directory\n", argv[0]);
                        }
                }
                else
                {
                        wait(&status);
                }
        }
}
