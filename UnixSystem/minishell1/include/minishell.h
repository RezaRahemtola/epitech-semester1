/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** header
*/

#ifndef MINISHELL_H
    #define MINISHELL_H
    #include "my.h"
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct str_s {
    char *str;
    struct str_s *next;
} str_t;

typedef struct builtin_s {
    char *command;
    int (*fun_ptr)(char **argv, str_t **env);
} builtin_t;

// Parsing
char *get_command_path(char *command, str_t *env);

// Error handling
int check_errors(int argc, char **argv);

// General
int minishell(char **env);
int get_user_input(char ***argv, str_t *env);

// Builtins
int get_builtin(const char *command);
int my_cd(char **argv, str_t **env);
int my_setenv(char **argv, str_t **env);
int my_unsetenv(char **argv, str_t **env);
int my_env(char **argv, str_t **env);

// Env
char *get_env_value(str_t *env, char *name);
str_t *array_to_list(char **argv);
char **list_to_array(str_t *list);

// Linked list
void obj_destroy(str_t *obj);
void list_destroy(str_t *obj);
void my_putend(char *str, str_t **dest);
int my_list_len(str_t *list);

extern const builtin_t builtins[5];

#endif /* !MINISHELL_H */
