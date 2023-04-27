#include "shell.h"

/**
 * _eputs - print
 * @string: the string
 * Return: non
 */
void _eputs(char *string)
{
	int j = 0;

	if (!string)
		return;
	while (string[j] != '\0')
	{
		_eputchar(string[j]);
		j++;
	}
}

/**
 * _eputchar - writes character
 * @character: The character
 * Return: when success 1.
 */
int _eputchar(char character)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (character != BUF_FLUSH)
		buf[j++] = character;
	return (1);
}

/**
 * _putfd - writes
 * @character: The character to print
 * @fikedescriptor: The filedescriptor.
 * Return: O and errno is set appropriately.
 */
int _putfd(char character, int filedescriptor)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(filedescriptor, buf, j);
		j = 0;
	}
	if (character != BUF_FLUSH)
		buf[j++] = character;
	return (1);
}

/**
 * _putsfd - input string
 * @string: the string printed
 * @filedescriptor: the file
 * Return: the number of chars
 */
int _putsfd(char *string, int filedescriptor)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += _putfd(*string++, filedescriptor);
	}
	return (j);
}
