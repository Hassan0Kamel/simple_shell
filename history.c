#include "shell.h"

/**
 * get_history_file - get
 * @infos: parametered
 * Return: allocated
 */

char *get_history_file(info_t *infos)
{
	char *buf, *directory;

	directory = _getenv(infos, "HOME=");
	if (!directory)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, directory);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - creates
 * @infos: the
 * Return: 1
 */
int write_history(info_t *infos)
{
	ssize_t filedirectory;
	char *filename = get_history_file(infos);
	list_t *nodeed = NULL;

	if (!filename)
		return (-1);

	filedirectory = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (filedirectory == -1)
		return (-1);
	for (nodeed = infos->history; nodeed; nodeed = nodeed->next)
	{
		_putsfd(nodeed->str, filedirectory);
		_putfd('\n', filedirectory);
	}
	_putfd(BUF_FLUSH, filedirectory);
	close(filedirectory);
	return (1);
}

/**
 * read_history - reads histor
 * @infos: the par
 * Return: h success, 0 otherwise
 */
int read_history(info_t *infos)
{
	int i, last = 0, linecount = 0;
	ssize_t filedirectory, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(infos);

	if (!filename)
		return (0);

	filedirectory = open(filename, O_RDONLY);
	free(filename);
	if (filedirectory == -1)
		return (0);
	if (!fstat(filedirectory, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(filedirectory, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(filedirectory);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(infos, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(infos, buf + last, linecount++);
	free(buf);
	infos->histcount = linecount;
	while (infos->histcount-- >= HIST_MAX)
		delete_node_at_index(&(infos->history), 0);
	renumber_history(infos);
	return (infos->histcount);
}

/**
 * build_history_list - adds entryinked list
 * @infos: Structure containing potential arguments. Used to maintain
 * @buf: bufer
 * @linecounter: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *infos, char *buf, int linecounter)
{
	list_t *nodeed = NULL;

	if (infos->history)
		nodeed = infos->history;
	add_node_end(&nodeed, buf, linecounter);

	if (!infos->history)
		infos->history = nodeed;
	return (0);
}

/**
 * renumber_history - renumers the history lifter changes
 * @infos: Structure cont
 * Return: the new histcount
 */
int renumber_history(info_t *infos)
{
	list_t *nodeed = infos->history;
	int j = 0;

	while (nodeed)
	{
		nodeed->num = j++;
		nodeed = nodeed->next;
	}
	return (infos->histcount = j);
}
