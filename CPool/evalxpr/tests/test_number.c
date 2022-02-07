/*
** EPITECH PROJECT, 2021
** Tests Number
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include "../include/eval_expr.h"

Test(number, basic_test)
{
    char *str = "42+25";
    char **str_ptr = &str;

    cr_assert(number(str_ptr) == 42);
    cr_assert_str_eq(str, "+25");
}

Test(number, complex_example)
{
    char *str = "423058-6976";
    char **str_ptr = &str;

    cr_assert(number(str_ptr) == 423058);
    cr_assert_str_eq(str, "-6976");
}

Test(number, min_max_examples)
{
    char *str = "-2147483649+2147483647";

    cr_assert(number(&str) == 0);
    cr_assert_str_eq(str, "9+2147483647");
}

Test(number, max_min_examples)
{
    char *str = "2147483648-2147483648";

    cr_assert(number(&str) == 0);
    cr_assert_str_eq(str, "8-2147483648");
}
