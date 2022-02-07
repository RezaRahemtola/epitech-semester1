/*
** EPITECH PROJECT, 2021
** Tests list option
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(list_option, basic, .init=cr_redirect_stdout)
{
    char *paths[2] = {"lib/my/Makefile", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 1;
    my_flags->up_r = 0;
    my_flags->d = 0;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;

    list_option(paths, my_flags);
    cr_assert_stdout_eq_str("-rw-rw-r--. 1 reza reza 983 Nov 22 11:46 lib/my/Makefile\n");
    free(my_flags);
}

Test(list_option, with_g_flag, .init=cr_redirect_stdout)
{
    char *paths[2] = {"lib/my/Makefile", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 0;
    my_flags->up_r = 0;
    my_flags->d = 0;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 1;
    my_flags->a = 0;

    list_option(paths, my_flags);
    cr_assert_stdout_eq_str("-rw-rw-r--. 1 reza 983 Nov 22 11:46 lib/my/Makefile\n");
    free(my_flags);
}

Test(list_option, with_d_flag, .init=cr_redirect_stdout)
{
    char *paths[2] = {"include/", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 1;
    my_flags->up_r = 0;
    my_flags->d = 1;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;

    list_option(paths, my_flags);
    cr_assert_stdout_eq_str("drwxrwxr-x. 2 reza reza 4096 Nov 25 19:11 include/\n");
    free(my_flags);
}

Test(list_option, in_folder, .init=cr_redirect_stdout)
{
    char *paths[2] = {"bonus", "\0"};
    flags *my_flags = malloc(sizeof(flags));

    my_flags->l = 1;
    my_flags->up_r = 0;
    my_flags->d = 0;
    my_flags->low_r = 0;
    my_flags->t = 0;
    my_flags->g = 0;
    my_flags->a = 0;

    list_option(paths, my_flags);
    cr_assert_stdout_eq_str("total 4\n-rw-r--r--. 1 reza reza 158 Dec 2 13:42 README.md\n");
    free(my_flags);
}
