#include "shell.h"

/**
 **_strncpy - copy
 *@destination: the destination
 *@source: the source 
 *@amount: the amount 
 *Return: the string
 */
char *_strncpy(char *destination, char *source, int amount)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (source[i] != '\0' && i < amount - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates
 *@destination: the first.
 *@source: the second.
 *@amount: the amounted
 *Return: the strong
 */
char *_strncat(char *destination, char *source, int amount)
{
	int i, j;
	char *s = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < n)
	{
		destinatino[i] = source[j];
		i++;
		j++;
	}
	if (j < n)
		destinatino[i] = '\0';
	return (s);
}

/**
 *_strchr - locateing
 *@string: the string strang
 *@character: the character charter
 *Return: (s) s
 */
char *_strchr(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
