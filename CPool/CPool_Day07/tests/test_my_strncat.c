/*
** EPITECH PROJECT, 2021
** Tests MY_STRNCAT
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, tests)
{
    char dest[] = "Reza";

    cr_assert_str_eq(my_strncat(dest, "LeBG", 3), "RezaLeB");
}
