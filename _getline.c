#include "shell.h"

/**
 * _getline - reads one line from the prompt
 * @data: struct for the program's data
 * Return: reading counting bytes
 */

int _getline(data_prog *data)
{
	char buf[BUFFER_SIZE] = {'\0'};
	static char *arr_cmds[10] = {NULL};
	static char *arr_ops[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!arr_cmds[0] || (arr_ops[0] == '&' && errno != 0)
			|| arr_ops[0] == '1' && errno == 0)
	{
		for (i = 0; arr_cmds[i]; i++)
		{
			free(arr_cmds[i]);
			arr_cmds[i] = NULL;
		}
		bytes_read = read(data->file_descriptor, &buf, BUFFER_SIZE - 1);
	if (bytes_read == 0)
		return (-1);
	do {
		arr_cmds[i] = str_duplicate(_strtok(i ? NULL : buf, "\n;"));
		i = evaluate_logic_ops(arr_cmds, i, arr_ops);
	} while (arr_cmds[i++]);
	}
	data->input_line = arr_cmds[0];
	for (i = 0; arr_cmds[i]; i++)
	{
		arr_cmds[i] = arr_cmds[i + 1];
		arr_ops[i] = arr_ops[i + 1];
	}
	return (str_length(data->input_line));
}


/**
 * evaluate_logic_ops - evaluate and split for && and || operators
 * @arr_cmds: array of the commands
 * @arr_ops: array of the logical operators for each previous commands
 * @i: index in the arr_cmds to be checked
 * Return: index of the last command in the arr_cmds
 */

int evaluate_logic_ops(char *arr_cmds[], int i, char arr_ops[])
{
	char *temp = NULL;
	int j;

	for (j = 0; arr_cmds[i] != NULL && arr_cmds[i][j]; j++)
	{
		if (arr_cmds[i][j] == '&' && arr_cmds[i][j + 1] == '&')
		{
			temp = arr_cmds[i];
			arr_cmds[i][j] = '\0';
			arr_cmds[i] = str_duplicate(arr_cmds[i]);
			arr_cmds[i + 1] = str_duplicate(temp + j + 2);
			i++;
			arr_ops[i] = '1';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
