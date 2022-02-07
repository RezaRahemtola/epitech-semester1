/*
** EPITECH PROJECT, 2021
** Tests disp_stdarg.c
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsprintf.h"

Test(disp_stdarg, basic, .init=cr_redirect_stdout)
{
    disp_stdarg("csiis", 'X', "hi", 10, -3, "plop");
    cr_assert_stdout_eq_str("X\nhi\n10\n-3\nplop\n", "");
}

Test(disp_stdarg, neg_limit, .init=cr_redirect_stdout)
{
    disp_stdarg("ci", 'R', -2147483648);
    cr_assert_stdout_eq_str("R\n-2147483648\n");
}
