#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "macros.h"

/********** STRUCTURES *************/

/**
 * struct info - struct for the programs data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of executed commands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases
 */

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_line;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_prog;

/**
 * struct_builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(data_prog *data);
} builtins;

/********* MAIN FUNCTIONS **********/

void initialize_data(data_prog *data, int argc, char *argv[], char **env);
void sisifo(char *prompt, data_prog *data);
void handle_ctrl_c(int opr UNUSED);
int _getline(data_prog *data);
int evaluate_logic_ops(char *arr_cmds[], int i, char arr_ops[]);
void expand_variables(data_prog *data);
void expand_alias(data_prog *data);
int buffer_add(char *buffer, char *str_to_add);
void tokenize(data_prog *data);
char *_strtok(char *line, char *delim);
int execute(data_prog *data);
int builtins_list(data_prog *data);
char **tokenize_path(data_prog *data);
int find_program(data_prog *data);
void free_array_of_pointers(char **directories);
void free_recurrent_data(data_prog *data);
int builtin_exit(data_prog *data);
int builtin_cd(data_prog *data);
int set_work_directory(data_prog, char *new_dir);
int builtin_help(data_prog *data);
int builtin_alias(data_prog *data);
int builtin_env(data_prog *data);
int builtin_unset_env(data_prog *data);
char *env_get_key(char *name, data_prog *data);
int env_set_key(char *key, char *value, data_prog *data);
int env_remove_key(char *key, data_prog *data);
void print_environ(data_prog *data);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_prog *data);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
int *str_concat(char *string1, char *string2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
int print_alias(data_prog *data, char *alias);
char *get_alias(data_prog *data, char *alias);
int set_alias(char *alias_string, data_prog *data);

#endif
