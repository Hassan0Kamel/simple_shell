#include "shell.h"

/**
 * is_cmd - determicommand
 * @infos: the infoss
 * @paths: path file
 * Return: 1 0
 */
int is_cmd(info_t *infos, char *paths)
{
	struct stat we;

	(void)infos;
	if (!paths || stat(paths, &we))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - dupliccters
 * @pathstring: thePATHstring
 * @start: index
 * @stop: stoppingi
 * Return: poinbuffer
 */
char *dup_chars(char *pathstring, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstring[i] != ':')
			buf[k++] = pathstring[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - findPATHstring
 * @infos: the info struct
 * @pathstring: the PATH string
 * @command: the cmd to find
 * Return: fulund or NULL
 */
char *find_path(info_t *infos, char *pathstring, char *command)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstring)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (is_command(infos, command))
			return (command);
	}
	while (1)
	{
		if (!pathstring[i] || pathstring[i] == ':')
		{
			path = dup_chars(pathstring, curr_pos, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstring[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
