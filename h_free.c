#include "shell.h"

/**
 * free_recurrent_data - frees the allocated memory for reccurrent data
 * @data: struct of the program's data
 */

void free_recurrent_data(data_prog *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->cmd_name)
		free(data->cmd_name);
	data->input_line = NULL;
	data->cmd_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - free all allocated memory of the data
 * @data: struct for the program's data
 */

void free_all_data(data_prog *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - frees each pointer of an array of
 * pointers and the array also
 * @array: array of pointer
 */

void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);
		free(array);
		array = NULL;
	}
}
