/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(infin_add, contains_zero)
{
    cr_assert_str_eq(infin_add("0", "42", 0, 0), "42");
    cr_assert_str_eq(infin_add("658368565822", "0", 0, 0), "658368565822");
    cr_assert_str_eq(infin_add("0", "0", 0, 0), "0");
}

Test(infin_add, same_number_digits)
{
    cr_assert_str_eq(infin_add("3", "5", 0, 0), "8");
    cr_assert_str_eq(infin_add("42", "69", 0, 0), "111");
    cr_assert_str_eq(infin_add("8637", "2480", 0, 0), "11117");
}

Test(infin_add, negative_values)
{
    cr_assert_str_eq(infin_add("-42", "-27", 0, 0), "-69");
    cr_assert_str_eq(infin_add("-42", "27", 0, 0), "-15");
    cr_assert_str_eq(infin_add("42", "-27", 0, 0), "15");
    cr_assert_str_eq(infin_add("-42", "0", 0, 0), "-42");
    cr_assert_str_eq(infin_add("83", "-83", 0, 0), "0");
    //cr_assert_str_eq(infin_add("1000", "-100", 0, 0), "900");
    //cr_assert_str_eq(infin_add("100", "-1000", 0, 0), "-900");
}

Test(infin_add, random_tests)
{
    cr_assert_str_eq(infin_add("999", "999", 0, 0), "1998");
    cr_assert_str_eq(infin_add("1000", "-1000", 0, 0), "0");
}
