#include "shell.h"

/**
 * builtin_env - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: On success 0, or other numbers in the argument if declarable
 */

int builtin_env(data_prog *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_cp = NULL;

	if (data->tokens[i] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				var_cp = str_duplicate(env_get_key(cpname, data));
				if (var_cp != NULL)
				env_set_key(cpname, data->tokens[1] + i + 1, data);
				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cpname, var_cp, data);
					free(var_cp);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->cmd_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - activate a new environment, or alter an existing one
 * @data: struct for the program's data
 * Return: On success 0
 */

int builtin_set_env(data_prog *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd_name);
		return (5);
	}
	env_set_key(data->tokens[1], data->tokens[2], data);
	return (0);
}

/**
 * builtin_unset_env - remove an environment variable
 * @data: struct for the program's data
 * Return: On success 0
 */

int buitlin_unset_env(data_prog *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);
	return (0);
}
