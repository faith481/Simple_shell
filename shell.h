#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>


void prom(const char *xter);
void program_exec(const char *order, char *const cas[], char *prog);
void interactive_form(char *prog, char *const envm[]);
void function_exec(const char *order, char *const cas[], char *prog);
void non_interactive_form(char *prog, char *const envm[]);
void strtak(const char *xter, char *prog);


#endif /*MAIN_H*/

