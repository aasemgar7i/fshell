#include "shell.h"

int main(int ac, char **av, char **envp)
{
	envp = allpaths();
	char *input = NULL;
	size_t len = 0;
	char **args = NULL;

	while (1)
	{
		printf("#OURSHELL$ ");
		if (getline(&input, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (input[0] == '\0' || input[0] == '\n' && input[1] == '\0')
			continue;
		if (strcmp(input, "exit") == 0)
		{
			printf("Good Bye.\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(input, "env") == 0)
		{
			print_env();
		}

		args = spliter(input);
		exefin(args, envp);

		for (int i = 0; args[i] != NULL; i++)
        	{
            		free(args[i]);
		}
		free(args);
	}
	free(input);
	free(envp);
	return 0;
}
