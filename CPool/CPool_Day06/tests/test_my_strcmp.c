/*
** EPITECH PROJECT, 2021
** Tests MY_STRCMP
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, tests)
{
    cr_assert(my_strcmp("ABC", "ABC") == 0);
    cr_assert(my_strcmp("ABA", "ABZ") == -25);
    cr_assert(my_strcmp("ABZ", "ABA") == 25);
    cr_assert(my_strcmp("ABC", "AB") == 67);
    cr_assert(my_strcmp("AB", "ABCDEFG") == -67);
    cr_assert(my_strcmp("ABCD", "") == 65);
    cr_assert(my_strcmp("", "A") == -65);
    cr_assert(my_strcmp("", "") == 0);
}
