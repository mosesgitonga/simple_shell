#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
	char buffer[1024];
	while (1)
	{
		printf("$ ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "env") == 0)
		{
			print_env();
		}
		else if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		else
		{
			system(buffer);
		}
		

	}
	display();
	handle_path();
	return (0);
}
