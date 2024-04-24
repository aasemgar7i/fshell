#include "shell.h"

/**
 * allpaths - get path
 * Return: all the path
 */

char **allpaths(void)
{
	char *path = getenv("PATH");
	char *pathd = strdup(path);
	char *token = strtok(pathd, ":");
	char **envp = NULL;
	int i = 0;
	int j = 0;

	envp = malloc(2 * sizeof(char *));
	while (token)
	{
		envp[i] = malloc(strlen(token) + 6);
		if (envp[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(envp[j]);
			}
			free(envp);
			free(pathd);
			return NULL;
		}
		sprintf(envp[i], "PATH=%s", token);
		i++;
		token = strtok(NULL, ":");
/**			if (token != NULL)
			{
				i++;
				envp = realloc(envp, (i + 1) * sizeof(char *));
			} */
	}
	envp[i] = NULL;
	free(pathd);
	return (envp);
}
