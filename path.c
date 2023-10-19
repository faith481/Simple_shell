#include "shell.h"

int check_file(char *full_path);

/**
 * find_program - find a program in path
 * @data: a pointer to the program's data
 * Return: On success 0, errorcode otherwise
 */

int find_program(data_prog *data)
{
	int i = 0, ret_code = 0;
	char **dir;

	if (!data->cmd_name)
		return (2);
	if (data->cmd_name[0] == '/' || data->cmd_name[0] == '.')
		return (check_file(data->cmd_name));
	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->cmd_name);
	if (!data->tokens[0])
		return (2);
	dir = tokenize_path(data);
	if (!dir || dir[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; dir[i]; i++)
	{
		dir[i] = str_concat(dir[i], data->tokens[0]);
		ret_code = check_file(dir[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(dir[i]);
			free_array_of_pointers(dir);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(dir);
	return (ret_code);
}

/**
 * tokenize_path - tokenize the path in the directories
 * @data: struct for the program's data
 * Return: array of path directories
 */

char **tokenize_path(data_prog *data)
{
	int i = 0;
	int count_dir = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}
	PATH = str_duplicate(PATH);
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			count_dir++;
	}
	tokens = malloc(sizeof(char *) * count_dir);
	i = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, ":"));
	}
	free(PATH);
	PATH = NULL;
	return (tokens);
}

/**
 * check_file - checks if a file exists, if its not a directory and
 * if its has execution permissions
 * @full_path: pointer to the full file name
 * Return: On success 0, otherwise errorcode
 */

int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) || access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
