#include "shell.h"

/**
 * **strtow - sprs are ignored
 * @string: the ining
 * @ding: the dng
 * Return: a pon failure
 */

char **strtow(char *string, char *ding)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || string[0] == 0)
		return (NULL);
	if (!ding)
		ding = " ";
	for (i = 0; string[i] != '\0'; i++)
		if (!is_delim(string[i], d) && (is_delim(string[i + 1], d) || !string[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(string[i], d))
			i++;
		k = 0;
		while (!is_delim(string[i + k], d) && string[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - sp words
 * @string: the iut string
 * @ding: the dter
 * Return: a pointer
 */
char **strtow2(char *string, char ding)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] != d && string[i + 1] == ding) ||
				    (string[i] != ding && !string[i + 1]) || string[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (string[i] == d && string[i] != ding)
			i++;
		k = 0;
		while (string[i + k] != ding && string[i + k] && string[i + k] != ding)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
