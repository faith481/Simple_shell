#include "shell.h"

/**
 * env_get_key - gets the value of an environment variable
 * @key: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */

char *env_get_key(char *key, data_prog *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length)
				&& data->env[i][key_length] == '=')
	{
		return (data->env[i] + key_length + 1);
	}
	}
	return (NULL);
}

/**
 * env_set_key - overwrite the value of the environment variables
 * or create it if it doesn't exist
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: On success 0, if the parameters are NULL 1, if there is an error 2
 */

int env_set_key(char *key, char *value, data_prog *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length)
				&& data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);
	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove a key from the environment
 * @key: the key to remove
 * @data: struct of the program's data
 * Return: if the key was removed 1, if the key does not exist 0
 */

int env_remove_key(char *key, data_prog *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);
	key_length = str_length(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length)
				&& data->env[i][key_length] == '=')
		{
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}

/**
 * print_environ - prints the current environment
 * @data: struct for the program's data
 */

void print_environ(data_prog *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
