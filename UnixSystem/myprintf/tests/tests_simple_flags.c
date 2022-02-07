/*
** EPITECH PROJECT, 2021
** Tests simple flags
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

Test(simple_flags, string_flag, .init=cr_redirect_stdout)
{
    const char *str = "%s";
    my_printf(str, "It works");
    cr_assert_stdout_eq_str("It works", "");
}

Test(simple_flags, string_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "It %s !\n";
    my_printf(str, "works");
    cr_assert_stdout_eq_str("It works !\n", "");
}

Test(simple_flags, string_flag_in_percent_str, .init=cr_redirect_stdout)
{
    const char *str = "It %s %%!\n";
    my_printf(str, "works");
    cr_assert_stdout_eq_str("It works %!\n", "");
}

Test(simple_flags, int_flag, .init=cr_redirect_stdout)
{
    const char *str = "%i";
    my_printf(str, 7);
    cr_assert_stdout_eq_str("7", "");
}

Test(simple_flags, int_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "God's number is %d !\n";
    my_printf(str, 42);
    cr_assert_stdout_eq_str("God's number is 42 !\n", "");
}

Test(simple_flags, char_flag, .init=cr_redirect_stdout)
{
    const char *str = "%c";
    my_printf(str, 48);
    cr_assert_stdout_eq_str("0", "");
}

Test(simple_flags, char_flag_in_str, .init=cr_redirect_stdout)
{
    const char *str = "I%c works !\n";
    my_printf(str, 116);
    cr_assert_stdout_eq_str("It works !\n", "");
}