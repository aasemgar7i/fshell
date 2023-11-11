#include "shell.h"

void tokinput(char *input, char *cmds[][10], int *num_cmds)
{
	char *token = strtok(input, " ");
	int count = 0;
	int cmd_index = 0;

	while (token != NULL)
	{
		if (strcmp(token, "|") == 0)
		{
			cmds[cmd_index][count] = NULL;
			cmd_index++;
			count = 0;
		} else
		{
			cmds[cmd_index][count++] = token;
		}
		token = strtok(NULL, " ");
	}
	if (count > 0)
	{
		cmds[cmd_index][count] = NULL;
		cmd_index++;
	}
}
