/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Main functions
*/

#include <signal.h>
#include "minishell.h"

const builtin_t builtins[5] = {{"cd", &my_cd}, {"env", &my_env},
{"setenv", &my_setenv}, {"unsetenv", &my_unsetenv}, {NULL, NULL}};

static int parent_waiting(void)
{
    int wstatus = 0;

    wait(&wstatus);
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGFPE)
            my_puterror("Floating exception");
        else
            my_puterror(strsignal(WTERMSIG(wstatus)));
        if (WCOREDUMP(wstatus))
            my_puterror(" (core dumped)");
        my_puterror("\n");
    }
    if (WIFEXITED(wstatus))
        return (WEXITSTATUS(wstatus));
    return (0);
}

static int exec_command(char *command, char **argv, str_t **env_list)
{
    int exit = 0;
    int builtin_index = get_builtin(argv[0]);
    char **env_array = list_to_array(*env_list);

    if (builtin_index != -1) {
        exit = builtins[builtin_index].fun_ptr(argv, env_list);
    } else if (fork() == 0) {
        execve(command, argv, env_array);
    } else {
        exit = parent_waiting();
    }
    my_free_2d_array(env_array);
    return (exit);
}

int minishell(char **original_env)
{
    char **argv = NULL;
    char *command = NULL;
    str_t *env_list = array_to_list(original_env);
    int exit = 0;

    while (get_user_input(&argv, env_list) != -1) {
        if (argv == NULL || argv[0] == NULL || argv[0][0] == '\0')
            continue;
        if (my_strcmp(argv[0], "exit") == 0) {
            exit = (argv[1] != NULL) ? my_getnbr(argv[1]) : 0;
            my_free_2d_array(argv);
            break;
        }
        if ((command = get_command_path(argv[0], env_list)) != NULL)
            exit = exec_command(command, argv, &env_list);
        my_free_2d_array(argv);
        free(command);
    }
    list_destroy(env_list);
    return (exit);
}
