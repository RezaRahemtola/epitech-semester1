/*
** EPITECH PROJECT, 2021
** Tests MY_STRCAT
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strcat(char *dest, char const *src);

Test(my_strcat, tests)
{
    char dest[] = "Reza";

    cr_assert_str_eq(my_strcat(dest, "LeBG"), "RezaLeBG");
}
