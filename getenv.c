#include "shell.h"

/**
 * get_environ - returning
 * @informatics: Structureed
 * Return: sometimes 0
 */


char **get_environ(info_t *informatics)
{
	if (!informatics->environ || informatics->env_changed)
	{
		informatics->environ = list_to_strings(informatics->env);
		informatics->env_changed = 0;
	}

	return (informatics->environ);
}

/**
 * _unsetenv - Remove an
 * @infos: Structure contai
 * @vari: the s
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_t *infos, char *vari)
{
	list_t *nodeed = infos->env;
	size_t i = 0;
	char *p;

	if (!nodeed || !vari)
		return (0);

	while (nodeed)
	{
		p = starts_with(nodeed->str, vari);
		if (p && *p == '=')
		{
			infos->env_changed = delete_node_at_index(&(infos->env), i);
			i = 0;
			nodeed = infos->env;
			continue;
		}
		nodeed = nodeed->next;
		i++;
	}
	return (infos->env_changed);
}

/**
 * _setenv - Initialize a new e
 * @infos: Structure containings
 * @vari: the string env var property
 * @valu: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *infos, char *vari, char *valu)
{
	char *buf = NULL;
	list_t *nodeed;
	char *p;

	if (!vari || !valu)
		return (0);

	buf = malloc(_strlen(vari) + _strlen(valu) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, vari);
	_strcat(buf, "=");
	_strcat(buf, valu);
	nodeed = infos->env;
	while (nodeed)
	{
		p = starts_with(nodeed->str, vari);
		if (p && *p == '=')
		{
			free(nodeed->str);
			nodeed->str = buf;
			infos->env_changed = 1;
			return (0);
		}
		nodeed = nodeed->next;
	}
	add_node_end(&(infos->env), buf, 0);
	free(buf);
	infos->env_changed = 1;
	return (0);
}
