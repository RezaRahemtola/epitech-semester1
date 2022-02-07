/*
** EPITECH PROJECT, 2021
** Tests MY_STRDUP
** File description:
** Test
*/

#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup, tests)
{
    cr_assert_str_eq(my_strdup("RezaLeBG"), strdup("RezaLeBG"));
    cr_assert_str_eq(my_strdup(""), strdup(""));
}
