/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "eval_expr.h"
#include "bistromatic.h"
#include "my.h"

Test(eval_expr, basic_test)
{
    char *str = "(3+2)*5";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "25");
}

Test(eval_expr, advanced_test)
{
    char *str = "(((3*5)/10)+4)%2+5/2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "3");
}

Test(eval_expr, minus_before_parenthesis)
{
    char *str = "-(12-(4*32))";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "116");
}

Test(eval_expr, big_big_big_big_big_test)
{
    char *str = "‘-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "-744629760");
}

Test(eval_expr, infin_add_sub)
{
    char *str = "2548952667426578456213465213156553456996-2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "2548952667426578456213465213156553456994");
}

Test(eval_expr, only_mult)
{
    char *str = "4*2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "8");
}

Test(eval_expr, only_div)
{
    char *str = "4/2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "2");
}

Test(eval_expr, only_mod)
{
    char *str = "4%2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "0");
}

Test(eval_expr, no_mult_div_mod)
{
    char *str = "4+2";

    cr_assert_str_eq(eval_expr("()+-*/%", str), "6");
}

