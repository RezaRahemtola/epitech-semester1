/*
** EPITECH PROJECT, 2022
** bs minishell
** File description:
** step 1
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int count_words(const char *str)
{
    int is_last_space = 1;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_last_space == 1 && str[i] != ' ')
            words++;
        is_last_space = (str[i] == ' ') ? (1) : (0);
    }
    return (words);
}

static char **str_to_word_array(char *str)
{
    int nb_words = count_words(str);
    int nb_chars = 0;
    char **array = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0; i < nb_words; i++) {
        while (str[nb_chars] != ' ' && str[nb_chars] != '\0') nb_chars++;
        array[i] = malloc(sizeof(char) * (nb_chars + 1));
        my_strncpy(array[i], str, nb_chars);
        str += nb_chars;
        while (str[0] == ' ') str++;
        nb_chars = 0;
    }
    array[nb_words] = NULL;
    return (array);
}

static int get_arr_len(char **arr)
{
    int i = 0;

    while (*arr) {
        i++;
        arr++;
    }
    return (i);
}

static char **get_arr_without_first(char **arr)
{
    char **new = malloc(sizeof(char *) * (get_arr_len(arr)));

    for (int i = 1; arr[i] != NULL; i++) {
        new[i - 1] = arr[i];
    }
    new[get_arr_len(arr) - 1] = NULL;
    return (new);
}

int main(int argc, char **argv, char **env)
{
    char **array = str_to_word_array(argv[1]);
    int arr_len = get_arr_len(array);
    int pid = 0;
    int status;

    argc = argc;
    my_printf("Program name: %s\n", array[0]);
    my_printf("Nb args: %d\n", arr_len - 1);
    my_printf("PID: %d\n", getpid());
    pid = fork();
    if (pid == 0) {
        my_printf("Child PID: %d\n", getpid());
        execve(array[0], get_arr_without_first(array), env);
    } else {
        wait(&status);
        my_printf("Program terminated.\n");
        if (WTERMSIG(status) == 0) my_printf("Status: OK\n");
        else my_printf("Status: %s\n", strsignal(WTERMSIG(status)));
    }
    return (0);
}
