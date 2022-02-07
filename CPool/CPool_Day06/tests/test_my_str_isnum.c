/*
** EPITECH PROJECT, 2021
** Tests MY_STR_ISNUM
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, tests)
{
    cr_assert(my_str_isnum("5835254542368223623623") == 1);
    cr_assert(my_str_isnum("56f5c24755dr") == 0);
    cr_assert(my_str_isnum("") == 1);
}
