#include "shell.h"

/**
 * interactive_form - check form in interactive
 * @prog: pointer to the shell
 * @envm: pointer to the array
 * Return: void
 */
void interactive_form(char *prog, char *const envm[])
{
	char *buffe = NULL;
	size_t y;

	y = 0;

	while (1)
	{
		prom("$ ");

		if (getline(&buffe, &y, stdin) == -1)
		{
			free(buffe);
			exit(0);
		}
		if (strncmp(buffe, "exit", 4) == 0)
		{
			free(buffe);
			exit(0);
		}
		else if (strncmp(buffe, "env", 3) == 0)
		{
			int j;

			for (j = 0; envm[j] != NULL; j++)
			{
				prom(envm[j]);
				prom("\n");
			}
		}
		else
		{
			strtak(buffe, prog);
		}
	}
}


/**
 * non_interactive_form - check form in non interactive
 * @prog: pointer to the shell
 * @envm: pointer to the array
 * Return: void
 */
void non_interactive_form(char *prog, char *const envm[])
{
	char *buffe = NULL;
	size_t y;

	y = 0;

	while (1)
	{
		if (getline(&buffe, &y, stdin) == -1)
		{
			free(buffe);
			break;
		}
		if (strncmp(buffe, "exit", 4) == 0)
		{
			free(buffe);
			break;
		}
		else if (strncmp(buffe, "env", 3) == 0)
		{
			int j;

			for (j = 0; envm[j] != NULL; j++)
			{
				prom(envm[j]);
				prom("\n");
			}
		}
		else
		{
			strtak(buffe, prog);
		}
	}
}

