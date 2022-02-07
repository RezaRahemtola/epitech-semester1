/*
** EPITECH PROJECT, 2021
** Tests MY_REVSTR
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, tests)
{
    char str[] = "Reza";

    cr_assert_str_eq(my_revstr(str), "azeR");
}
