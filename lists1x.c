#include "shell.h"

/**
 * list_len - deternked list
 * @k: pointer to first node
 * Return: sizst
 */
size_t list_len(const list_t *k)
{
	size_t m = 0;

	while (k)
	{
		k = k->next;
		m++;
	}
	return (m);
}

/**
 * list_to_strings - reture list->str
 * @header: poin node
 * Return: arstrings
 */
char **list_to_strings(list_t *header)
{
	list_t *node = header;
	size_t m = list_len(header), j;
	char **strs;
	char *str;

	if (!header || !m)
		return (NULL);
	strs = malloc(sizeof(char *) * (m + 1));
	if (!strs)
		return (NULL);
	for (m = 0; node; node = node->next, m++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < m; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[m] = str;
	}
	strs[m] = NULL;
	return (strs);
}


/**
 * print_list - printsllellist
 * @k: poinode
 * Return: sizest
 */
size_t print_list(const list_t *k)
{
	size_t m = 0;

	while (k)
	{
		_puts(convert_number(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->next;
		m++;
	}
	return (m);
}

/**
 * node_starts_with - returns nh prefix
 * @noded: pointer to list head
 * @prefixx: strmatch
 * @c: thetch
 * Return: match node or null
 */
list_t *node_starts_with(list_t *noded, char *prefixx, char c)
{
	char *p = NULL;

	while (noded)
	{
		p = starts_with(noded->str, prefixx);
		if (p && ((c == -1) || (*p == c)))
			return (noded);
		node = noded->next;
	}
	return (NULL);
}

/**
 * get_node_index - getsof a node
 * @header: poi head
 * @noded: poer to the node
 * Return: ine or -1
 */
ssize_t get_node_index(list_t *header, list_t *noded)
{
	size_t f = 0;

	while (header)
	{
		if (header == noded)
			return (fi);
		header = head->next;
		f++;
	}
	return (-1);
}
