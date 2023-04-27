#include "shell.h"

/**
 * _myexit - quit the shell
 * @informatics: Structure containing. Used to
 * constanting a prototype
 * Return: exit without a given exit
 */
int _myexit(info_t *informatics)
{
	int exitchecker;

	if (informatics->argv[1]) /* If there is an exit arguement */
	{
		exitchecker = _erratoi(informatics->argv[1]);
		if (exitchecker == -1)
		{
			informatics->status = 2;
			print_error(informatics, "Illegal number: ");
			_eputs(informatics->argv[1]);
			_eputchar('\n');
			return (1);
		}
		informatics->err_num = _erratoi(informatics->argv[1]);
		return (-2);
	}
	informatics->err_num = -1;
	return (-2);
}

/**
 * _mycd - change the directory currently
 *
 * @informatics: Structure containing potential. Used to maintain
 * constant function ing aprototype.
 * Return: Always 0
 */
int _mycd(info_t *informatics)
{
	char *s, *direc, bufer[1024];
	int chdir_rett;

	s = getcwd(bufer, 1024);
	if (!s)
		_puts("failed successfully\n");
	if (!informatics->argv[1])
	{
		direc = _getenv(informatics, "HOME=");
		if (!direc)
			chdir_rett =
				chdir((direc = _getenv(informatics, "PWD=")) ? direc : "/");
		else
			chdir_rett = chdir(direc);
	}
	else if (_strcmp(informatics->argv[1], "-") == 0)
	{
		if (!_getenv(informatics, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(informatics, "OLDPWD=")), _putchar('\n');
		chdir_rett =
			chdir((direc = _getenv(informatics, "OLDPWD=")) ? direc : "/");
	}
	else
		chdir_rett = chdir(informatics->argv[1]);
	if (chdir_rett == -1)
	{
		print_error(informatics, "can't cd to ");
		_eputs(informatics->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(informatics, "OLDPWD", _getenv(informatics, "PWD="));
		_setenv(informatics, "PWD", getcwd(bufer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @informatics: Structure containing potential. Used to maintain
 * constant function ing aprototype.
 * Return: Always 0
 */
int _myhelp(info_t *informatics)
{
	char **arg_arrayed;

	arg_arrayed = informatics->argv;
	_puts("help call works. Functioern not yet implemerented \n");
	if (0)
		_puts(*arg_arrayed); /* temp att_unused workaround */
	return (0);
}
