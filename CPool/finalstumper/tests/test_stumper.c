/*
** EPITECH PROJECT, 2021
** Tests stumper
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "rush3.h"

Test(stumper, basic_test)
{
    char *str = "o--o\n|  |\no--o\n";

    cr_assert_str_eq(stumper(str), "[rush1-1] 4 3\n");
}

Test(stumper, special_case_one)
{
    char *str = "*\n";

    cr_assert_str_eq(stumper(str), "[rush1-2] 1 1\n");
}

Test(stumper, special_case_two)
{
    char *str = "o-o\n";

    cr_assert_str_eq(stumper(str), "[rush1-1] 3 1\n");
}

Test(stumper, special_case_three)
{
    char *str = "BBBB\n";

    cr_assert_str_eq(stumper(str), "[rush1-3] 4 1 || [rush1-4] 4 1 || [rush1-5] 4 1\n");
}

Test(stumper, special_case_four)
{
    char *str = "o\n|\n|\no\n";

    cr_assert_str_eq(stumper(str), "[rush1-1] 1 4\n");
}

Test(stumper, invalid_size)
{
    char *str = "";

    cr_assert_str_eq(stumper(str), "none\n");
}

Test(stumper, big_size)
{
    char *str = "/*************\\\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n*             *\n\\*************/\n";

    cr_assert_str_eq(stumper(str), "[rush1-2] 15 17\n");    
}

Test(stumper, none)
{
    char *str = "ziohjgisinj";

    cr_assert_str_eq(stumper(str), "none\n");
}
