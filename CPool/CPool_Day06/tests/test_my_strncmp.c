/*
** EPITECH PROJECT, 2021
** Tests MY_STRNCMP
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, tests)
{
    cr_assert(my_strncmp("ABC", "AB", 3) == 67);
    cr_assert(my_strncmp("ABC", "AB", 2) == 0);
    cr_assert(my_strncmp("AB", "ABC", 3) == -67);
    cr_assert(my_strncmp("", "", 2) == 0);
    cr_assert(my_strncmp("ABC", "", 2) == 65);
    cr_assert(my_strncmp("", "ABCDEF", 2) == -65);
}
