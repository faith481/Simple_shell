#include "shell.h"


/**
 * strtak - print function that tokenize the strings
 * @xter: The strings
 * @prog: pointer to the shell
 *
 * Return: void
 */
void strtak(const char *xter, char *prog)
{
	const char *delimi = " \n";
	char *tak = strdup(xter), *next_orde = NULL;
	int w, count = 0;
	char *next_tak[10];

	if (tak == NULL)
	{
		perror("Failed to allocate memory");
		return;
	}
	next_orde = strtok(tak, delimi);

	while (count < 10 && next_orde != NULL)
	{
		next_tak[count] = strdup(next_orde);
		count++;
		next_orde = strtok(NULL, delimi);
	}
	if (count > 0)
	{
		next_tak[count] = NULL;
		function_exec(next_tak[0], next_tak, prog);

		for (w = 0; w < count; w++)
		{
			free(next_tak[w]);
		}
	}
	free(tak);
}


/**
 * prom - print the function that display prompt
 * @xter: prompt
 * Return: void
 */
void prom(const char *xter)
{
	write(STDOUT_FILENO, xter, strlen(xter));
}
