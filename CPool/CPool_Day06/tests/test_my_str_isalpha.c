/*
** EPITECH PROJECT, 2021
** Tests MY_STR_ISALPHA
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, tests)
{
    cr_assert(my_str_isalpha("HfrhiygnwrnrghueFrjnEerji") == 1);
    cr_assert(my_str_isalpha("jowndh lpodm") == 0);
    cr_assert(my_str_isalpha("") == 1);
}
