#include "shell.h"

/**
 * main - entint
 * @acr: count
 * @avr: vector
 * Return: 0 or 1
 */
int main(int acr, char **avr)
{
	info_t info[] = { INFO_INIT };
	int filedirectory = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (filedirectory)
			: "r" (filedirectory));

	if (acr == 2)
	{
		filedirectory = open(avr[1], O_RDONLY);
		if (filedirectory == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(avr[0]);
				_eputs(": 0: Can't open ");
				_eputs(avr[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = filedirectory;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, avr);
	return (EXIT_SUCCESS);
}
