#include "shell.h"

/**
 * function_exec - print function that execute a command
 * @order: executed command
 * @cas: arguments
 * @prog: pointer to the shell
 * Return: void
 */
void function_exec(const char *order, char *const cas[], char *prog)
{
	if (access(order, X_OK) == 0)
	{
		pid_t pt_pid = fork();

		if (pt_pid == -1)
		{
			perror("Fork has failed");
			return;
		}

		if (pt_pid == 0)
		{
			execve(order, cas, NULL);
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
	else
	{
		program_exec(order, cas, prog);
	}
}

