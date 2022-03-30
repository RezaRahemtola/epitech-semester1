/*
** EPITECH PROJECT, 2021
** Tests my_printf
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(int_conversion, u_flag, .init=cr_redirect_stdout)
{
    const char *str = "%u";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("42", "");
}

Test(int_conversion, u_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %u !\n";
    my_printf(str, 0);
    cr_assert_stdout_eq_str("It 0 !\n", "");
}

Test(int_conversion, o_flag, .init=cr_redirect_stdout)
{
    const char *str = "%o";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("52", "");
}

Test(int_conversion, o_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %o !\n";
    my_printf(str, 0);
    cr_assert_stdout_eq_str("It 0 !\n", "");
}

Test(int_conversion, x_flag, .init=cr_redirect_stdout)
{
    const char *str = "%x";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("2a", "");
}

Test(int_conversion, x_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %x !\n";
    my_printf(str, 69);
    cr_assert_stdout_eq_str("It 45 !\n", "");
}

Test(int_conversion, X_flag, .init=cr_redirect_stdout)
{
    const char *str = "%X";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("2A", "");
}

Test(int_conversion, X_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %X !\n";
    my_printf(str, 69);
    cr_assert_stdout_eq_str("It 45 !\n", "");
}

Test(int_conversion, b_flag, .init=cr_redirect_stdout)
{
    const char *str = "%b";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("101010", "");
}

Test(int_conversion, b_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %b !\n";
    my_printf(str, 69);
    cr_assert_stdout_eq_str("It 1000101 !\n", "");
}