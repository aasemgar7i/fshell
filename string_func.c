#include "shell.h"
/**
 * _strcmp - string compare
 * @s1: first string
 * @s2: second string
 * Return: 1 f true 0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 * _strcpy - string copy
 * @dest: string destination
 * @src: string source
 * Return: pointer to the destiation string
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return (p);
}
/**
 * _strcat - string concat
 * @dest: string destination
 * @src: string source
 * Return: pointer to the destiation string
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p != '\0')
		++p;
	while (*src != '\0')
	{
		*p = *src;
		++p;
		++src;
	}
	*p = '\0';
	return (dest);
}
/**
 * _strlen - string length
 * @str: string to count
 * Return: the length
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: string
 */
char *_strdup(char *str)
{
	char *p;
	size_t size;


	if (str == NULL)
		return NULL;

	size = strlen(str) + 1;
	p = malloc(size);

	if (p == NULL)
		return NULL;

	strcpy(p, str);

	return p;
/**	char *p;
	int i, size;

	if (str == 0)
		return (0);
	size = 0;
	while (str[size] != '\0')
		size++;
	p = malloc(sizeof(char) * (size + 1));
	if (p == 0)
		return (0);
	for (i = 0; i < size; i++)
	{
		p[i] = str[i];
	}
	p[size] = '\0';
	return (p); */
}
