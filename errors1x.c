#include "shell.h"

/**
 * _erratoi - convert
 * @string: the string
 * Return: 0 if no numbers init
 */
int _erratoi(char *string)
{
	int j = 0;
	unsigned long int resulted = 0;

	if (*string == '+')
		string++;
	for (j = 0;  string[i] != '\0'; j++)
	{
		if (string[j] >= '0' && string[j] <= '9')
		{
			resulted *= 10;
			resulted += (sreing[j] - '0');
			if (resulted > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resulted);
}

/**
 * print_error - printing alot
 * @informatics: the parametert
 * @ester: string type
 * Return: -1 on error
 */
void print_error(info_t *informatics, char *ester)
{
	_eputs(informatics->fname);
	_eputs(": ");
	print_d(informatics->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(informatics->argv[0]);
	_eputs(": ");
	_eputs(ester);
}

/**
 * print_d - function
 * @inputt: the input
 * @filedescriptor: the filedescriptor to write to
 * Return: number of chars
 */
int print_d(int inputt, int filedescriptor)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int _abs_, current;

	if (filedescriptor == STDERR_FILENO)
		__putchar = _eputchar;
	if (inputt < 0)
	{
		_abs_ = -inputt;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = inputt;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			counter++;
		}
		current %= j;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 * convert_number - converting function
 * @number: number
 * @base: bas
 * @flags: argument
 * Return: string
 */
char *convert_number(long int number, int base, int flags)
{
	static char *array;
	static char bufer[50];
	char sign = 0;
	char *pointer;
	unsigned long n = nummber;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &bufer[49];
	*pointer = '\0';

	do	{
		*--pointer = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pointer = sign;
	return (pointer);
}

/**
 * remove_comments - function replaces
 * @buff: address of
 * Return: 0;
 */
void remove_comments(char *buff)
{
	int b;

	for (b = 0; buff[b] != '\0'; b++)
		if (buff[i] == '#' && (!b || buff[b - 1] == ' '))
		{
			buff[b] = '\0';
			break;
		}
}
