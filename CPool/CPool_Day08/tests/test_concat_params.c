/*
** EPITECH PROJECT, 2021
** Tests CONCAT_PARAMS
** File description:
** Tests
*/

#include <criterion/criterion.h>

char *concat_params(int argc, char **argv);

Test(concat_params, tests)
{
    char *args[3];

    args[0] = "./unit_tests";
    args[1] = "toto";
    args[2] = "titi";
    cr_assert_str_eq(concat_params(3, args), "./unit_tests\ntoto\ntiti");
}
