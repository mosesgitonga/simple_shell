#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;
#include <stddef.h>
#include <sys/types.h>
extern char **environ;
int simple_shell(int ac, char **argv);
int display();

int simple_shell(int ac, char **argv);


#endif
