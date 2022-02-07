/*
** EPITECH PROJECT, 2021
** Tests parenthesis
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include "../include/eval_expr.h"

Test(parenthesis, basic_test)
{
    char *str = "(3*5)";

    cr_assert_str_eq(parenthesis(&str), "15");
}

Test(parenthesis, advanced_test)
{
    char *str = "(3+2)*5";

    cr_assert_str_eq(parenthesis(&str), "5*5");
}
