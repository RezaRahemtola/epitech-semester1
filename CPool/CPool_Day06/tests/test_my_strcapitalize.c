/*
** EPITECH PROJECT, 2021
** Tests MY_STRCAPITALIZE
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, tests)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";
    char result[] = "Hey, How Are You? 42words Forty-Two; Fifty+One";

    cr_assert_str_eq(my_strcapitalize(str), result);
}
