#include "shell.h"

/**
 * getcmd - return cmd if found in PATH
 * @cmd: the command passed
 * Return: pointer to founded path command
 */

char *getcmd(char *cmd)
{
	char *token = NULL, *path = getenv("PATH"), *command = NULL, *cp;
	struct stat st;

	if (!path)
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	else if (*path == '\0')
		perror("PATH");
	else
	{
		cp = _strdup(path);
		token = strtok(cp, ":");
	}
	while (token != NULL)
	{
		if (!_strstr(cmd, "/"))
		{
			command = malloc(_strlen(token) + _strlen(cmd) + 2);
			_strcpy(command, token);
			_strcat(command, "/");
			_strcat(command, cmd);
			_strcat(command, "\0");
		}
		else
			command = _strdup(cmd);
		if (stat(command, &st) == 0)
		{
			free(cp);
			return (command); /*full cmd from path*/
		}
		token = strtok(NULL, ":"); /*check next value*/
	}
	free(cp);
	return (NULL);/*usr cmd not found in path*/
}
