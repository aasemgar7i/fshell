#include "shell.h"

extern char **environ;

void exefin(char **av, char **envp)
{
	pid_t pi = fork();
	int status;
	char *cmdfp = getcmd(av[0]);

	if (pi == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pi == 0)
	{

		if (execve(cmdfp, av, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(pi, &status, 0);
	}
}
