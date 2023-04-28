#include "shell.h"

/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument   vector
 *
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm (
		"mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd)
	);

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			errno == EACCES ? exit(126) : (void)0;
			errno == ENOENT ? (
				_eputs(av[0]), _eputs(": 0: Can't open "),
				_eputs(av[1]), _eputchar('\n'), _eputchar(BUF_FLUSH),
				exit(127)
			) : exit(EXIT_FAILURE);
		}
		info->readfd = fd;
	}

	populate_env_list(info);
	read_history(info);
	hsh(info, av);

	return EXIT_SUCCESS;
}
