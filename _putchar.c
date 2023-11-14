#include "shell.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _putchars(const char *str)
{
	while(*str)
	{
		_putchar(*str);
		str++;
	}
}
