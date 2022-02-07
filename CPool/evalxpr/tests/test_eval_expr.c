/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(eval_expr, basic_test)
{
    char *str = "(3+2)*5";

    cr_assert(eval_expr(str) == 25);
}

Test(eval_expr, advanced_test)
{
    char *str = "(((3*5)/10)+4)%2+5/2";

    cr_assert(eval_expr(str) == 3);
}

Test(eval_expr, minus_before_parenthesis)
{
    char *str = "-(12-(4*32))";

    cr_assert(eval_expr(str) == 116);
}

Test(eval_expr, big_big_big_big_big_test)
{
    char *str = "‘-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))";

    cr_assert(eval_expr(str) == -744629760);
}
