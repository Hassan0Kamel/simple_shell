environ.c

#include "shell.h"

/**
 * _myenv - printi the current environment.
 * @informatics: Structure containing arguments
 * Return: jusst 0
 */
int _myenv(info_t *informatics)
{
	print_list_str(informatics->env);
	return (0);
}

/**
 * _getenv - getting the value of an variable
 * @informatics: Structure
 * @nameofvariable: var name
 * Return: a value
 */
char *_getenv(info_t *informatics, const char *nameofvariable)
{
	list_t *nodeed = informatics->env;
	char *d;

	while (nodeed)
	{
		d = starts_with(nodeed->str, nameofvariable);
		if (d && *d)
			return (d);
		nodeed = nodeed->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize
 * @informatics: Structure containing potential arguments good
 *  Return: pribably 0
 */
int _mysetenv(info_t *informatics)
{
	if (informatics->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}


	if (_setenv(info, informatics->argv[1], informatics->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove avariable
 * @informatics: Structure containing potential goodness
 * Return: Always null
 */
int _myunsetenv(info_t *informatics)
{
	int j;

	if (informatics->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= informatics->argc; j++)
		_unsetenv(informatics, informatics->argv[j]);

	return (0);
}

/**
 * populate_env_list - populates
 * @info: Structure containing 
 * Return: kinda 0
 */




int populate_env_list(info_t *informatics)
{
	list_t *nodeed = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&nodeed, environ[j], 0);
	info->env = nodeed;
	return (0);
}
