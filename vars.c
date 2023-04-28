#include "shell.h"

/**
 * is_chain - tea chain delimeter
 * @infos: the info
 * @buff: the char buffer
 * @p: addsition in buf
 * Return: 1 or no 0 ote
 */
int is_chain(info_t *infos, char *buff, size_t *p)
{
	size_t j = *p;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		infos->cmd_buf_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		infos->cmd_buf_type = CMD_AND;
	}
	else if (buff[j] == ';') /* find end of this command */
	{
		buff[j] = 0; /* replace semicolon with null */
		infos->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we shoued on last status
 * @info: the paract
 * @buf: the char buffer
 * @p: addion in buf
 * @i: starn buf
 * @len: len buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - reptokenized string
 * @infos: the ptruct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *infos)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(infos->alias, infos->argv[0], '=');
		if (!node)
			return (0);
		free(infos->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		infos->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaenized string
 * @infos: the pruct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *infos)
{
	int i = 0;
	list_t *node;

	for (i = 0; infos->argv[i]; i++)
	{
		if (infos->argv[i][0] != '$' || !infos->argv[i][1])
			continue;

		if (!_strcmp(infos->argv[i], "$?"))
		{
			replace_string(&(infos->argv[i]),
					_strdup(convert_number(infos->status, 10, 0)));
			continue;
		}
		if (!_strcmp(infos->argv[i], "$$"))
		{
			replace_string(&(infos->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(infos->env, &infos->argv[i][1], '=');
		if (node)
		{
			replace_string(&(infos->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&infos->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - rep string
 * @old: addrstring
 * @new: new sg
 * Return: 1 if therwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
