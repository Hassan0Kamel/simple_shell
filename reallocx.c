#include "shell.h"

/**
 * _memset - fills ant byte
 * @s: the poory area
 * @b: the th
 * @n: thefilled
 * Return: (sory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - freerings
 * @tt: string of strings
 */
void ffree(char **tt)
{
	char **a = tt;

	if (!tt)
		return;
	while (*tt)
		free(*tt++);
	free(a);
}

/**
 * _realloc - reallocatmory
 * @pointer: pointer to palloc'ated block
 * @old_size: bytous block
 * @new_size: byte ck
 * Return: pointmeen.
 */
void *_realloc(void *ointerr, unsigned int old_size, unsigned int new_size)
{
	char *l;

	if (!pointer)
		return (malloc(new_size));
	if (!new_size)
		return (free(pointer), NULL);
	if (new_size == old_size)
		return (pointer);

	l = malloc(new_size);
	if (!l)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		l[old_size] = ((char *)pointer)[old_size];
	free(pointer);
	return (l);
}
