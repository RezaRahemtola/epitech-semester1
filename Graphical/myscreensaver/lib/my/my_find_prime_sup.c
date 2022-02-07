/*
** EPITECH PROJECT, 2021
** MY_FIND_PRIME_SUP
** File description:
** Task07
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}
