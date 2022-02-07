/*
** EPITECH PROJECT, 2021
** Tests my_printf
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(basic, basic_str, .init=cr_redirect_stdout)
{
    const char *str = "It works";
    my_printf(str);
    cr_assert_stdout_eq_str("It works", "");
}

Test(basic, basic_str_line_break, .init=cr_redirect_stdout)
{
    const char *str = "It works\n";
    my_printf(str);
    cr_assert_stdout_eq_str("It works\n", "");
}