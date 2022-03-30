/*
** EPITECH PROJECT, 2021
** Tests advanced flags
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"
#include "my.h"

Test(advanced_flags, S_flag, .init=cr_redirect_stdout)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 6;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\006to\n", "");
}

Test(advanced_flags, ld_flag, .init=cr_redirect_stdout)
{
    my_printf("%ld", 123456789123);
    cr_assert_stdout_eq_str("123456789123");
}

Test(advanced_flags, lo_flag, .init=cr_redirect_stdout)
{
    my_printf("%lo", 123456789123);
    cr_assert_stdout_eq_str("1627646215203");
}

Test(advanced_flags, lX_flag, .init=cr_redirect_stdout)
{
    my_printf("%lX", 123456789123);
    cr_assert_stdout_eq_str("1CBE991A83");
}

Test(advanced_flags, lld_flag, .init=cr_redirect_stdout)
{
    my_printf("%lld", 123456789123);
    cr_assert_stdout_eq_str("123456789123");
}

Test(advanced_flags, llo_flag, .init=cr_redirect_stdout)
{
    my_printf("%llo", 123456789123);
    cr_assert_stdout_eq_str("1627646215203");
}

Test(advanced_flags, llX_flag, .init=cr_redirect_stdout)
{
    my_printf("%llX", 123456789123);
    cr_assert_stdout_eq_str("1CBE991A83");
}
