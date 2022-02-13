/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to handle input
*/

#include "minishell.h"

static char *get_pattern(char **str)
{
    int i = 0;
    char *pattern = NULL;

    while ((*str)[0] == ' ' || (*str)[0] == '\t')
        (*str)++;
    while ((*str)[i] != ' ' && (*str)[i] != '\t' && (*str)[i] != '\0')
        i++;
    pattern = my_str_allocfill(i + 1, '\0');
    my_strncpy(pattern, *str, i);
    (*str) += i;
    while ((*str)[0] == ' ' || (*str)[0] == '\t')
        (*str)++;
    return (pattern);
}

static char **input_to_argv(char *input)
{
    list_t *list = NULL;
    list_t *tmp = NULL;
    char *pattern = NULL;
    char **argv = NULL;
    int len = 0;

    for (; input[0] != '\0'; len++) {
        pattern = get_pattern(&input);
        mylist_append(my_strdup(pattern), &list);
        free(pattern);
    }
    argv = malloc(sizeof(char *) * (len + 1));
    tmp = list;
    for (int i = 0; tmp != NULL; i++) {
        argv[i] = my_strdup(tmp->data);
        tmp = tmp->next;
    }
    argv[len] = NULL;
    mylist_destroy(list, true);
    return (argv);
}

static char *get_replaced_buffer(char *buffer, list_t *env)
{
    char *new_buffer = NULL;
    char *home_path = get_env_value(env, "HOME=");

    if (my_strstr(buffer, "~") == NULL || home_path == NULL) {
        new_buffer = my_strdup(buffer);
        free(buffer);
        free(home_path);
        return (new_buffer);
    }
    new_buffer = my_streplace(buffer, "~", home_path);
    free(home_path);
    free(buffer);
    return (new_buffer);
}

int get_user_input(char ***argv, list_t *env)
{
    size_t size = 0;
    int read = 0;
    char *buffer = NULL;
    char *replaced_buffer = NULL;

    if (isatty(0))
        my_putstr("$> ");
    read = getline(&buffer, &size, stdin);
    if (read != -1) {
        buffer[read - 1] = '\0';
        replaced_buffer = get_replaced_buffer(buffer, env);
        (*argv) = input_to_argv(replaced_buffer);
    }
    free(replaced_buffer);
    return (read);
}
