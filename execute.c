#include "shell.h"

/**
 * execute - executes a command with its entire path variables
 * @data: a pointer to the program's data
 * Return: on Success 0, otherwise -1
 */

int execute(data_prog *data)
{
	int result = 0, status;
	pid_t child_pid;

	result = builtins_list(data);
	if (result != -1)
		return (result);
	result = find_prog(data);
	if (result)
	{
		return (result);
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(data->cmd_name);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			result = execve(data->tokens[0], data->tokens, data->env);
			if (result == -1)
				perror(data->cmd_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
