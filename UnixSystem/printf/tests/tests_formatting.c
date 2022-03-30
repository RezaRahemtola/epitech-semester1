/*
** EPITECH PROJECT, 2021
** Tests formatting
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"
#include "my.h"

Test(formatting, hash_x, .init=cr_redirect_stdout)
{
    const char *str = "%#x";
    my_printf(str, 150);
    cr_assert_stdout_eq_str("0x96", "");
}

Test(formatting, hash_x_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %#x\n";
    my_printf(str, 29);
    cr_assert_stdout_eq_str("It 0x1d\n", "");
}

Test(formatting, hash_x_zero, .init=cr_redirect_stdout)
{
    const char *str = "It %#x\n";
    my_printf(str, 0);
    cr_assert_stdout_eq_str("It 0\n", "");
}

Test(formatting, hash_X, .init=cr_redirect_stdout)
{
    const char *str = "%#X";
    my_printf(str, 150);
    cr_assert_stdout_eq_str("0X96", "");
}

Test(formatting, hash_X_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %#X\n";
    my_printf(str, 29);
    cr_assert_stdout_eq_str("It 0X1D\n", "");
}

Test(formatting, hash_X_zero, .init=cr_redirect_stdout)
{
    const char *str = "It %#X\n";
    my_printf(str, 0);
    cr_assert_stdout_eq_str("It 0\n", "");
}

Test(formatting, hash_o, .init=cr_redirect_stdout)
{
    const char *str = "%#o";
    my_printf(str, 29);
    cr_assert_stdout_eq_str("035", "");
}

Test(formatting, hash_o_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %#o\n";
    my_printf(str, 150);
    cr_assert_stdout_eq_str("It 0226\n", "");
}

Test(formatting, hash_o_zero, .init=cr_redirect_stdout)
{
    const char *str = "It %#o\n";
    my_printf(str, 0);
    cr_assert_stdout_eq_str("It 0\n", "");
}
