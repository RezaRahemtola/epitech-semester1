/*
** EPITECH PROJECT, 2021
** Tests MY_STR_IS_UPPER
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, tests)
{
    cr_assert(my_str_isupper("BHFIJFJDYFLJCFHJFGHDH") == 1);
    cr_assert(my_str_isupper("HHEDHRHGHRFHBEF5JFDJDFKGFMJ") == 0);
    cr_assert(my_str_isupper("") == 1);
}
