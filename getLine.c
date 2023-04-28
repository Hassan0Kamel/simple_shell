#include "shell.h"

/**
 * input_buf - buffers commands
 * @info: parameter
 * @buff: address buffer
 * @len: address of
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buff, size_t *len)
{
	ssize_t rt = 0;
	size_t len_r = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rt = getline(buff, &len_r, stdin);
#else
		rt = _getline(info, buff, &len_r);
#endif
		if (rt > 0)
		{
			if ((*buff)[rt - 1] == '\n')
			{
				(*buff)[rt - 1] = '\0'; /* remove trailing newline */
				rt--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = rt;
				info->cmd_buf = buff;
			}
		}
	}
	return (rt);
}

/**
 * get_input - gets a
 * @informatics: parameter struct
 * Return: sunbytes
 */
ssize_t get_input(info_t *informatics)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t rt = 0;
	char **buff_p = &(informatics->arg), *p;

	_putchar(BUF_FLUSH);
	rt = input_buf(informatics, &buff, &len);
	if (rt == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buff + i; /* get pointer for return */



		check_chain(informatics, buff, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(informatics, buff, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			informatics->cmd_buf_type = CMD_NORM;
		}

		*buff_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buff_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (rt); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads
 * @informatics: parameter
 * @buff: buffer
 * @size: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *informatics, char *buff, size_t *size)
{
	ssize_t rt = 0;

	if (*size)
		return (0);
	rt = read(informatics->readfd, buff, READ_BUF_SIZE);
	if (rt >= 0)
		*size = rt;
	return (rt);
}

/**
 * _getline - gets the
 * @informatics: par struct
 * @pointer: address of pointerL
 * @length: size of preallocated ptr buffer.
 * Return: s
 */
int _getline(info_t *informatics, char **pointer, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pointer;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(informatics, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*pointer = p;
	return (s);
}

/**
 * sigintHandler - blocks
 * @sig_num: signal number
 * Return: (void)
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
