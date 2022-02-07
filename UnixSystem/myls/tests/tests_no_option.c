/*
** EPITECH PROJECT, 2021
** Tests no option
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(no_option, basic, .init=cr_redirect_stdout)
{
    char *paths[2] = {"include", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 0;
    my_flags->up_r = 0;
    my_flags->d = 0;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;

    no_option(paths, my_flags);
    cr_assert_stdout_eq_str("my.h\nmy_ls.h\nutils.h\n");
    free(my_flags);
}

Test(no_option, with_d_flag, .init=cr_redirect_stdout)
{
    char *paths[2] = {"include/", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 0;
    my_flags->up_r = 0;
    my_flags->d = 1;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;

    no_option(paths, my_flags);
    cr_assert_stdout_eq_str("include/\n");
    free(my_flags);
}
