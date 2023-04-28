#include "shell.h"

/**
 * _strcpy - ctring
 * @destination: thion
 * @src: turce
 * Return: poi stination
 */
char *_strcpy(char *destination, char *src)
{
	int i = 0;

	if (destination == src || src == 0)
		return (destination);
	while (src[i])
	{
		destination[i] = src[i];
		i++;
	}
	destination[i] = 0;
	return (destination);
}

/**
 * _strdup - dupling
 * @string: t duplicate
 * Return: po tring
 */
char *_strdup(const char *string)
{
	int length = 0;
	char *rett;

	if (string == NULL)
		return (NULL);
	while (*string++)
		length++;
	rett = malloc(sizeof(char) * (length + 1));
	if (!rett)
		return (NULL);
	for (length++; length--;)
		rett[length] = *--string;
	return (rett);
}

/**
 * _puts - printstring
 * @string: the strrinted
 * Return: Nothing
 */
void _puts(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}

/**
 * _putchar - writ to stdout
 * @c: The cint
 * Return: On s
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
