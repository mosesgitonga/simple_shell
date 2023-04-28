#include "shell.h"

/**
 * _myexit- to get out of shell
 * @info:strucure
 *  Return:exit
 */

int _myexit(info_t *info)
{
	int exitcheck;

	switch (info->argv[1] != NULL) {
		case 1:
			exitcheck = _erratoi(info->argv[1]);
			if (exitcheck == -1)
			{
				info->status = 2;
				print_error(info, "Illegal number: ");
				_eputs(info->argv[1]);
				_eputchar('\n');
				return (1);
			}
			info->err_num = _erratoi(info->argv[1]);
			return (-2);
		default:
			info->err_num = -1;
			return (-2);
	}
}

/**
 * _mycd- same as cd
 * @info:struct
 *  Return: 0
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	switch (info->argv[1] == NULL) {
		case 1:
			dir = _getenv(info, "HOME=");
			if (!dir)
				chdir_ret = 
					chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
			else
				chdir_ret = chdir(dir);
			break;
		default:
			if (_strcmp(info->argv[1], "-") == 0)
			{
				if (!_getenv(info, "OLDPWD="))
				{
					_puts(s);
					_putchar('\n');
					return (1);
				}
				_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
				chdir_ret = 
					chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
			}
			else
				chdir_ret = chdir(info->argv[1]);
			break;
	}

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp-current directory of the process
 * @info: Struct
 *  Return:0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");

	switch (0) {
		case 1:
			_puts(*arg_array); 
			break;
	}

	return (0);
}
