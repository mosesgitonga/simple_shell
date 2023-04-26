#include "main.h"

char *get_location(char *, char **);
void execute(char **, char **);
char *_getenv(char *, char **);
void _free(char **argv);

void _free(char **argv)

{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char *_getenv(char *name, char **env)
{
	char *value = NULL;
	size_t i;
	size_t name_len = _strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if ((_strncmp(name, env[i], name_len) == 0) &&
				(env[i][name_len] == '='))
		{
			value = &env[i][name_len + 1];
			break;
		}
	}
	return (value);
}

char *get_location(char *command, char **env)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, dir_length;
	struct stat buffer;

	path = _getenv("PATH", env);
	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			file_path = malloc(sizeof(char) * (command_length + dir_length + 2));
			if (file_path == NULL)
				return (NULL);

			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}


void execute(char **argv, char **env)
{
	char *command_str = NULL, *command = NULL;
	pid_t pid, wpid;
	int status;

	if (argv)
	{
		command_str = argv[0];
		_strcpy_at(command_str, argv[0], _strlen("/bin/"));

		command = get_location(command_str, env);

		if (command == NULL)
		{
			perror("./hsh");
			return;
		}

		pid = fork();
		if (pid == 0)
		{
			/* execution */
			if (execve(command, argv, env) == -1)
			{
				free(command);
				_free(argv);
				perror("./hsh");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("./hsh");
		}
		else
		{
			do {
				wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	(void)command;
	(void)wpid;
	_free(argv);
}


