#include "shell.h"

/**
 * builtins_list - search for a match and execute the associate builtin
 * @data: struct for the prpgram's data
 * Return: the return value of the function executed
 * if there's a match, otherwise -1
 */

int builtins_list(data_prog *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_unset_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, data->cmd_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
