/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** header
*/

#ifndef MINISHELL_H
    #define MINISHELL_H
    #include "my.h"
    #include "mylist.h"
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct builtin_s {
    char *command;
    int (*fun_ptr)(char **argv, list_t **env);
} builtin_t;

typedef struct command_s {
    char *path;
    char **argv;
} command_t;

// Parsing
char *get_command_path(char *command, list_t *env);

// General
int minishell(char **env);
int get_user_input(command_t **command, list_t *env);

// Execute
int exec_command(command_t *command, list_t **env_list, bool *is_exit);

// Builtins
int get_builtin(const char *command);
int my_cd(char **argv, list_t **env);
int my_setenv(char **argv, list_t **env);
int my_unsetenv(char **argv, list_t **env);
int my_env(char **argv, list_t **env);
int my_exit(char **argv, list_t **env);

// Env
char *get_env_value(list_t *env, char *name);

extern const builtin_t builtins[6];

#endif /* !MINISHELL_H */
