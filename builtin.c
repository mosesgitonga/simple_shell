#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include "main.h"
void print_env(void)
{
	char **env;
        for (env = environ; *env; env++)
        {
                printf("%s\n", *env);
        }
}
