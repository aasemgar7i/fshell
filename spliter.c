#include "shell.h"

/**
 * spliter - split string into arguents
 * @input: iput to splite
 * Return: array of arguments
 */

char **spliter(const char *input)
{
	char *token = NULL;
	char *copy = strdup(input);
	unsigned int i = 0;
	char **args = NULL;

	token = strtok(copy, " \n\\");
	args = malloc(sizeof(char *));

	while (token)
	{
		if (args == NULL)
			perror("malloc");
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("malloc");
			free(args);
		}
		strcpy(args[i], token);
		token = strtok(NULL, " \n\\");
		i++;
		args = realloc(args, (i + 1) * sizeof(char *));
	}
	args[i] = NULL;
	return args;
}
