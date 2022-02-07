/*
** EPITECH PROJECT, 2021
** Tests MY_STRSTR
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, tests)
{
    cr_assert_str_eq(my_strstr("BlablarezaBlabla", "reza"), "rezaBlabla");
    cr_assert_null(my_strstr("BlablarezaBlabla", "test"));
    cr_assert_str_eq(my_strstr("Hello", "lo"), "lo");
    cr_assert_str_eq(my_strstr("marvin_is_back", "marvin_is_back"), "marvin_is_back");
    cr_assert_str_eq(my_strstr("marvin_is_backIl", "marvin_is_back"), strstr("marvin_is_backIl", "marvin_is_back"));
    cr_assert_str_eq(my_strstr("", "marvin_is_back"), strstr("", "marvin_is_back"));
    cr_assert_str_eq(my_strstr("marvin_is_back", ""), strstr("marvin_is_back", ""));
    cr_assert_str_eq(my_strstr("", ""), strstr("", ""));
}
