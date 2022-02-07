/*
** EPITECH PROJECT, 2021
** Tests MY_STR_ISLOWER
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, tests)
{
    cr_assert(my_str_islower("ahyhniebneiochnnbu") == 1);
    cr_assert(my_str_islower("fbuie1nvvkfo") == 0);
    cr_assert(my_str_islower("") == 1);
}
