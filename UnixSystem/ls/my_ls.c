/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** main file
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "my_ls.h"

static flags *init_flags(void)
{
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 0;
    my_flags->up_r = 0;
    my_flags->d = 0;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;
    return (my_flags);
}

int main(int argc, char **argv)
{
    flags *my_flags = init_flags();
    char **paths = parse_paths(argc, argv);
    int is_error = 0;

    parse_flags(argc, argv, my_flags);
    if (my_flags->l || my_flags->g)
        is_error = list_option(paths, my_flags);
    else
        is_error = no_option(paths, my_flags);
    free(paths);
    free(my_flags);
    return (is_error);
}
