#include "shell.h"


/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *prog = argv[0];
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		interactive_form(prog, argv);
	}
	else
	{
		non_interactive_form(prog, argv);
	}
	return (0);
}

