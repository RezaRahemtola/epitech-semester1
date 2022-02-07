/*
** EPITECH PROJECT, 2021
** Tests MY_STR_ISPRINTABLE
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, tests)
{
    cr_assert(my_str_isprintable("ndjsoue58'[)-3$") == 1);
    cr_assert(my_str_isprintable("frnei89ry\tvn") == 0);
    cr_assert(my_str_isprintable("") == 1);
}
