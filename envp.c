#include "shell.h"

char** allpaths()
{
	char *path = getenv("PATH");
	char *pathd = strdup(path);
	char *token = strtok(pathd, ":");
	char **envp = NULL;
	int i = 0;

	envp = malloc(sizeof(char *));
	while(token)
	{
		envp[i] = malloc(strlen(token) + 2);
		sprintf(envp[i], "PATH=%s", token);
		token = strtok(NULL, ":");
			if (token != NULL)
			{
				i++;
				envp = realloc(envp, (i + 1) * sizeof(char *));
			}
	}
	envp[i] = NULL;
	return envp;
}
