#include "shell.h"

#define SHELL_PROMPT "#OURSHELL$ "

/**
 * main - main of the simple shell project
 * @ac: nmber of args
 * @av: args
 * @envp: environment path
 * Return: always 0
 */

int main(int ac, char **av, char **envp)
{
	int i;
	size_t len = 0;
	char *input = NULL, **args = NULL;
	int is_terminal = isatty(fileno(stdin));

	(void) ac;
	(void) **av;
	envp = allpaths();
	while (1)
	{
		if (is_terminal)
		{
			printf(SHELL_PROMPT);
		}
		if (getline(&input, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (input[0] == '\0' || (input[0] == '\n' && input[1] == '\0'))
			continue;
		if (strcmp(input, "exit") == 0)
		{
			printf("Good Bye.\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(input, "env") == 0)
			print_env();

		args = spliter(input);
		exefin(args, envp);
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
	free(input);
	free(envp);
	return (0);
}
