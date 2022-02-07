/*
** EPITECH PROJECT, 2021
** Tests MY_PUTNBR_BASE
** File description:
** Tests
*/

#include <criterion/criterion.h>

int my_putnbr_base(int nbr, char const *base);

Test(my_putnbr_base, tests)
{
    my_putnbr_base(-86, "012");
}
