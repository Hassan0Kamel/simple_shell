#include "shell.h"

/**
 * _myhistory - display the history's list.
 * @informatics: Structure containing arguments
 *  Return: just 0
 */
int _myhistory(info_t *informatics)
{
	print_list(informatics->history);
	return (0);
}

/**
 * unset_alias - set alias to strings
 * @informatics: parameter structure.
 * @string: the string alia
 * Return: allwaayys 0
 */
int unset_alias(info_t *informatics, char *string)
{
	char *d, f;
	int rett;

	d = _strchr(string, '=');
	if (!d)
		return (1);
	f = *d;
	*d = 0;
	rett = delete_node_at_index(&(informatics->alias),
		get_node_index(informatics->alias,
			node_starts_with(informatics->alias, string, -1)));
	*d = f;
	return (rett);
}

/**
 * set_alias - set alias to string
 * @informatics: parameter structure
 * @string: the good strings alia
 * Return: 0 or 1
 */
int set_alias(info_t *informatics, char *string)
{
	char *d;

	d = _strchr(string, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(informatics, string));
	unset_alias(informatics, string);
	return (add_node_end(&(informatics->alias),
				string, 0) == NULL);
}

/**
 * print_alias - print alias string
 * @nodeed: alias's nodes
 * Return: 0 || 1
 */
int print_alias(list_t *nodeed)
{
	char *d = NULL, *g = NULL;

	if (nodeed)
	{
		d = _strchr(nodeed->str, '=');
		for (g = nodeed->str; g <= d; g++)
		_putchar(*g);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimic the alia builtin.
 * @informatics: Structure containing potential arguments
 *  Return: 0 and 0
 */
int _myalias(info_t *informatics)
{
	int j = 0;
	char *d = NULL;
	list_t *nodeed = NULL;

	if (informatics->argc == 1)
	{
		nodeed = informatics->alias;
		while (nodeed)
		{
			print_alias(nodeed);
			nodeed = nodeed->next;
		}
		return (0);
	}
	for (j = 1; informatics->argv[j]; j++)
	{
		d = _strchr(informatics->argv[j], '=');
		if (d)
			set_alias(informatics, informatics->argv[j]);
		else
			print_alias(node_starts_with(informatics->alias,
						informatics->argv[j], '='));
	}

	return (0);
}
