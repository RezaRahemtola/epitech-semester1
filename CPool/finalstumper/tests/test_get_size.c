/*
** EPITECH PROJECT, 2021
** Tests get_size
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "rush3.h"
#include "my.h"

Test(get_size, basic_test)
{
    char *buff = "o--o\n| |\n| |\no--o\n";

    cr_assert(get_size_x(buff) == 4);
    cr_assert(get_size_y(buff) == 4);
}

Test(get_size, advanced_test)
{
    char *buff = "o---o\n|  |\n|  |\n|  |\n|  |\no---o\n";

    cr_assert(get_size_x(buff) == 5);
    cr_assert(get_size_y(buff) == 6);
}
