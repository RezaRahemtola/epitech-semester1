/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Functions to parse arguments
*/

#include <stdlib.h>
#include "my_ls.h"

static void get_flag_from_str(char **argv, int i, flags *my_flags)
{
    for (int j = 1; j < my_strlen(argv[i]); j++) {
        if (argv[i][j] == 'l') my_flags->l = 1;
        if (argv[i][j] == 'R') my_flags->up_r = 1;
        if (argv[i][j] == 'd') my_flags->d = 1;
        if (argv[i][j] == 'r') my_flags->low_r = 1;
        if (argv[i][j] == 't') my_flags->t = 1;
        if (argv[i][j] == 'g') my_flags->g = 1;
        if (argv[i][j] == 'a') my_flags->a = 1;
    }
}

void parse_flags(int argc, char **argv, flags *my_flags)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && my_strlen(argv[i]) > 1)
            get_flag_from_str(argv, i, my_flags);
    }
}

static int count_potential_paths(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            count++;
    }
    return (count);
}

char **parse_paths(int argc, char **argv)
{
    int len = count_potential_paths(argc, argv);
    char **paths = malloc(sizeof(char *) * (len + 2));
    int index = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            paths[index] = argv[i];
            index++;
        }
    }
    if (len == 0)
        paths[len++] = ".";
    paths[len] = "\0";
    return (paths);
}
