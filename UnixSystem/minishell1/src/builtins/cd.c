/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Builtin - CD
*/

#include <errno.h>
#include "minishell.h"

static bool check_cd_errors(char **argv, str_t *env)
{
    char *path = get_env_value(env, "HOME=");

    if (my_arraylen(argv) > 2) {
        my_puterror("cd: Too many arguments.\n");
        free(path);
        return (true);
    }
    if (argv[1] == NULL && path == NULL) {
        my_puterror("cd: No home directory.\n");
        free(path);
        return (true);
    }
    free(path);
    return (false);
}

static char *get_cd_path(char **argv, str_t *env)
{
    if (argv[1] == NULL) {
        return (get_env_value(env, "HOME="));
    } else if (my_strcmp(argv[1], "-") == 0) {
        return (get_env_value(env, "OLDPWD="));
    } else {
        return (my_strdup(argv[1]));
    }
}

static int disp_chdir_error(char *path)
{
    my_puterror(path);
    my_puterror(": ");
    my_puterror(strerror(errno));
    my_puterror(".\n");
    return (1);
}

static void cd_update_env(char *old_dir, str_t **env)
{
    char *new_dir = getcwd(NULL, 0);

    my_setenv((char *[4]){"setenv", "OLDPWD", old_dir, NULL}, env);
    my_setenv((char *[4]){"setenv", "PWD", new_dir, NULL}, env);
    free(new_dir);
}

int my_cd(char **argv, str_t **env)
{
    char *path = NULL;
    int exit = 0;
    char *old_dir = getcwd(NULL, 0);

    if (check_cd_errors(argv, *env)) {
        free(old_dir);
        return (1);
    }
    path = get_cd_path(argv, *env);
    if (chdir(path) == -1)
        exit = disp_chdir_error(argv[1]);
    else
        cd_update_env(old_dir, env);
    free(old_dir);
    free(path);
    return (exit);
}
