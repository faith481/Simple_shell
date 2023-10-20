#include "shell.h"

/**
 * program_exec - prints function that execute a commands
 * @order: The command
 * @cas: argument array
 * @prog: pointer to the shell
 * Return: void
 */
void program_exec(const char *order, char *const cas[], char *prog)
{
	pid_t pt_pid = fork();

	if (pt_pid == -1)
	{
		perror("Fork has failed");
		return;
	}

	if (pt_pid == 0)
	{
		execvp(order, cas);
		perror(prog);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		pid_t child_pid;

		do {
			child_pid = wait(&status);
		} while (child_pid != pt_pid);
	}
}

