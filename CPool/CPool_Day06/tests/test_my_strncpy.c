/*
** EPITECH PROJECT, 2021
** Tests MY_STRNCPY
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, tests)
{
    char dest[] = "Test";
    char const *src = "Reza";

    cr_assert_str_eq(my_strncpy(dest, src, 2), "Rest");
    cr_assert_str_eq(my_strncpy(dest, src, 6), "Reza\0");
}
