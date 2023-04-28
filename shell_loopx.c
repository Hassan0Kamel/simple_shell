#include "shell.h"

/**
 * hsh - maop
 * @infos: the paro struct
 * @avr: the argumentvector f
 * Return: 0 onor code
 */
int hsh(info_t *infos, char **avr)
{
	ssize_t r = 0;
	int builtin_rett = 0;

	while (r != -1 && builtin_rett != -2)
	{
		clear_info(infos);
		if (interactive(infos))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(infos);
		if (r != -1)
		{
			set_info(infos, avr);
			builtin_rett = find_builtin(infos);
			if (builtin_rett == -1)
				find_cmd(infos);
		}
		else if (interactive(infos))
			_putchar('\n');
		free_info(infos, 0);
	}
	write_history(infos);
	free_info(infos, 1);
	if (!interactive(infos) && infos->status)
		exit(infos->status);
	if (builtin_rett == -2)
	{
		if (infos->err_num == -1)
			exit(infos->status);
		exit(infos->err_num);
	}
	return (builtin_rett);
}

/**
 * find_builtin - find ommand
 * @infos: the paramet struct
 * Return: -5 or 4
 */
int find_builtin(info_t *infos)
{
	int i, built_in_rett = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(infos->argv[0], builtintbl[i].type) == 0)
		{
			infos->line_count++;
			built_in_rett = builtintbl[i].func(info);
			break;
		}
	return (built_in_rett);
}

/**
 * find_cmd - findin PATH
 * @infos: the parameter &returni
 * Return: too much void
 */
void find_cmd(info_t *infos)
{
	char *path = NULL;
	int n, h;

	info->path = infos->argv[0];
	if (infos->linecount_flag == 1)
	{
		infos->line_count++;
		infos->linecount_flag = 0;
	}
	for (n = 0, h = 0; infos->arg[n]; i++)
		if (!is_delim(infos->arg[n], " \t\n"))
			h++;
	if (!h)
		return;

	path = find_path(infos, _getenv(infos, "PATH="), infos->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(infos);
	}
	else
	{
		if ((interactive(infos) || _getenv(infos, "PATH=")
					|| infos->argv[0][0] == '/') && is_cmd(infos, infos->argv[0]))
			fork_cmd(infos);
		else if (*(infos->arg) != '\n')
		{
			infos->status = 127;
			print_error(infos, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks run cmd
 * @infos: the paramet return info struct
 * Return: voidy
 */
void fork_cmd(info_t *infos)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infos->path, infos->argv, get_environ(infos)) == -1)
		{
			free_info(infos, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(infos->status));
		if (WIFEXITED(infos->status))
		{
			infos->status = WEXITSTATUS(infos->status);
			if (infos->status == 126)
				print_error(infos, "Permission denied\n");
		}
	}
}
