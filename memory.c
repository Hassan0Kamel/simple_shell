#include "shell.h"

/**
 * bfree - frd NULLs the address
 * @pointer: address pointer
 * Return: 1 rwise 0.
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
