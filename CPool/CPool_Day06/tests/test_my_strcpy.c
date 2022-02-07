/*
** EPITECH PROJECT, 2021
** Tests MY_STRCPY
** File description:
** Tests Task01
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, tests)
{
    char dest[] = "Test";
    char const *src = "Reza";

    cr_assert_str_eq(my_strcpy(dest, src), "Reza");
}
