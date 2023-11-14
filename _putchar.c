#include "shell.h"

/**
 * _putchar - main func
 * @c: input
 * Return: char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putchars - main func
 * @str: input
 */

void _putchars(const char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
