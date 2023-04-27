#include "shell.h"

/**
 * interactive - return (true) if shell is in
 * the interactive mode
 * @information: the address of the struc
 * Return: 1 if it's in the interactive mode,
 * 0 if not
 */
int interactive(info_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * is_delim - checking if the character is a delimeter
 * @check: the char to check
 * @del: the delimeter string
 * Return: 1 true, 0 if not
 */
int is_delim(char check, char *del)
{
	while (*del)
		if (*del++ == check)
			return (1);
	return (0);
}

/**
 *_isalpha - checking for alpha char
 *@character: The input
 *Return: 1 if char is alphabetic, 0 if not
 */

int _isalpha(int character)
{
	if ((character >= 'a' && character <= 'z') ||
			(character >= 'A' && character <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converting string to an integer
 *@string: the string to convert
 *
 *
 *Return: 0 if there's no number
 */

int _atoi(char *string)
{
	int j, siggn = 1, flagg = 0, ooutput;
	unsigned int results = 0;

	for (j = 0;  string[j] != '\0' && flagg != 2; j++)
	{
		if (string[j] == '-')
			siggn *= -1;

		if (string[j] >= '0' && string[j] <= '9')
		{
			flagg = 1;
			results *= 10;
			results += (string[j] - '0');
		}
		else if (flagg == 1)
			flagg = 2;
	}

	if (siggn == -1)
		ooutput = -results;
	else
		ooutput = results;

	return (ooutput);
}
