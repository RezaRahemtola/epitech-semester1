/*
** EPITECH PROJECT, 2021
** Tests MY_STRLOWCASE
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, tests)
{
    char str[] = "REZA Le BEsT.";

    cr_assert_str_eq(my_strlowcase(str), "reza le best.");
}
