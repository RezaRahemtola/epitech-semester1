/*
** EPITECH PROJECT, 2021
** Tests MY_STRUPCASE
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strupcase(char *str);

Test(my_strupcase, tests)
{
    char str[] = "Reza le best.";

    cr_assert_str_eq(my_strupcase(str), "REZA LE BEST.");
}
