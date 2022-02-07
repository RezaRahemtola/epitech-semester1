/*
** EPITECH PROJECT, 2021
** Tests summands
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(summands, basic_test)
{
    char *str = "-3";

    cr_assert(summands(&str) == -3);
}

Test(summands, mid_test)
{
    char *str = "-3-8+1";

    cr_assert(summands(&str) == -10);
}

Test(summands, advanced_test)
{
    char *str = "42+25+1+6+9+76+36-10-1";

    cr_assert(summands(&str) == 184);
}
