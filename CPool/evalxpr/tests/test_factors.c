/*
** EPITECH PROJECT, 2021
** Tests factors
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"
#include "../include/my.h"

Test(factors, basic_div_test)
{
    char *str = "42/2";

    cr_assert_str_eq(factors(&str), "21");
}

Test(factors, basic_mul_test)
{
    char *str = "42*2";

    cr_assert_str_eq(factors(&str), "84");
}

Test(factors, basic_modul_test)
{
    char *str = "42%10";

    cr_assert_str_eq(factors(&str), "2");
}

Test(factors, advanced_div_test)
{
    char *str = "42/2*2*4/2";

    cr_assert_str_eq(factors(&str), "84");
}

Test(factors, advanced_mul_test)
{
    char *str = "-89*63/5/3";

    cr_assert_str_eq(factors(&str), "-373");
}

Test(factors, advanced_modul_test)
{
    char *str = "-89%8*3";

    cr_assert_str_eq(factors(&str), "-3");
}

Test(factors, with_add_and_sub)
{
    char *str = "42+5*3-2+8/4-10%1";

    cr_assert_str_eq(factors(&str), "42+15-2+2-0");
}

Test(factors, edge_case_modulo)
{
    char *str = "5%2+5/2";

    cr_assert_str_eq(factors(&str), "1+2");
}
