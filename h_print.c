#include "shell.h"

/**
 * _print - writes an array of characters in the standard output
 * @string: pointer to the array of characters
 * Return: number of bytes written
 * on error, -1 is returned and errno is set appropriately
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}

/**
 * _printe - writes an array of characters in the standard error
 * @string: pointer to thr array of characters
 * Return: the number of bytes written
 * on error, -1 is returned and errno is set apptopriately
 */

int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - writes an array of charactera in the standard error
 * @data: a pointer to the program's data
 * @errorcode: error code to print
 * Return: number of bytes written
 * on error, -1 is returned and errno is set appropriately
 */

int _print_error(int errorcode, data_prog *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);
	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(":Illegal number: ");
		else
			_printe(": Can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->cmd_name);
		_printe(": Command not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->cmd_name);
		_printe(": Access denied\n");
	}
	return (0);
}
