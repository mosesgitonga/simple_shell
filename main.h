#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
extern char **environ;

void handle_path();
void print_env(void);
int display();
void exit_shell(void);
#endif

