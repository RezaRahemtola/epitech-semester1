/*
** EPITECH PROJECT, 2021
** Tests summands
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "eval_expr.h"
#include "bistromatic.h"

Test(summands, basic_test)
{
    char *str = "-3";

    cr_assert_str_eq(summands(&str), "-3");
}

Test(summands, mid_test)
{
    char *str = "-3-8+1";

    cr_assert_str_eq(summands(&str), "-10");
}

Test(summands, advanced_test)
{
    char *str = "42+25+1+6+9+76+36-10-1";

    cr_assert_str_eq(summands(&str), "184");
}

Test(summands, full_minus_test)
{
    char *str = "-42--2";

    cr_assert_str_eq(summands(&str), "-40");
}

Test(summands, pattern_test_one)
{
    char *str = "2--2";

    cr_assert_str_eq(summands(&str), "4");
}

Test(summands, pattern_test_two)
{
    char *str = "-2+-2";

    cr_assert_str_eq(summands(&str), "-4");
}

Test(summands, pattern_test_three)
{
    char *str = "-2--2";

    cr_assert_str_eq(summands(&str), "0");
}

Test(summands, pattern_test_four)
{
    char *str = "2+2";

    cr_assert_str_eq(summands(&str), "4");
}

Test(summands, pattern_test_five)
{
    char *str = "2--2";

    cr_assert_str_eq(summands(&str), "4");
}

Test(summands, pattern_test_six)
{
    char *str = "-2-2";

    cr_assert_str_eq(summands(&str), "-4");
}

Test(summands, pattern_test_seven)
{
    char *str = "-2+-2";

    cr_assert_str_eq(summands(&str), "-4");
}

Test(summands, pattern_test_eight)
{
    char *str = "-2+2";

    cr_assert_str_eq(summands(&str), "0");
}

Test(summands, pattern_test_nine)
{
    char *str = "2+-2";

    cr_assert_str_eq(summands(&str), "0");
}

Test(summands, pattern_test_ten)
{
    char *str = "2-2";

    cr_assert_str_eq(summands(&str), "0");
}
