#include "shell.h"

/**
 * print_env - print the current envirionment
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}
