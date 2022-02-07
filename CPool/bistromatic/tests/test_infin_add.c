/*
** EPITECH PROJECT, 2021
** test_infini_add
** File description:
** desc
*/

#include <criterion/criterion.h>
#include "my.h"
#include "infin_add.h"

Test(infin_add, contains_zero)
{
    cr_assert_str_eq(infin_add("0", "42"), "42");
    cr_assert_str_eq(infin_add("658368565822", "0"), "658368565822");
    cr_assert_str_eq(infin_add("0", "658368565822"), "658368565822");
    cr_assert_str_eq(infin_add("0", "0"), "0");
}

Test(infin_add, same_number_digits)
{
    cr_assert_str_eq(infin_add("3", "5"), "8");
    cr_assert_str_eq(infin_add("42", "69"), "111");
    cr_assert_str_eq(infin_add("8637", "2480"), "11117");
}

Test(infin_add, random_tests)
{
    cr_assert_str_eq(infin_add("999", "999"), "1998");
    cr_assert_str_eq(infin_add("54541564651654654654645456566446", "5461354653641466414623152352222111"), "5515896218293121069277797808788557");
    cr_assert_str_eq(infin_add("5544634646834632154632154321543215446213543154", "2"), "5544634646834632154632154321543215446213543156");
    cr_assert_str_eq(infin_add("5846523154614865468231456468235486648468146846346346468468344683", "5474552787768534685346823145623154612325421532154621323"), "5846523160089418255999991153582309794091301458671768000622966006");
}
