/*
** EPITECH PROJECT, 2022
** antman_project
** File description:
** antman
*/

#include <stdio.h>
#include "../include/antman.h"

char my_putcstr(unsigned char first_nb, unsigned char second_number)
{
    unsigned char result = 0;

    first_nb = first_nb << 4;
    printf("passe de 0000 0001 -> 0001 0000: %d\n", first_nb);
    result = first_nb | second_number;
    printf("compressed result: %d\n", result);
    return (result);
}

char *my_readcstr(unsigned char compressed_nb)
{
    unsigned char nb1;
    unsigned char nb2;
    char result[3];

    nb1 = compressed_nb >> 4;
    printf("nb1: %d\n", nb1);
    nb2 = compressed_nb << 4;
    nb2 = nb2 >> 4;
    printf("nb2: %d\n", nb2);
    result[0] = nb1 + '0';
    result[1] = nb2 + '0';
    result[2] = '\0';
    printf("decompressed result: %s\n", result);

    return (result);
}

int main(int ac, char **av)
{
    printf("nbr1: %c -> %d    |    nbr2: %c -> %d\n", my_getnbr(av[1]), my_getnbr(av[1]), my_getnbr(av[2]), my_getnbr(av[2]));
    unsigned char compressed = my_putcstr(my_getnbr(av[1]), my_getnbr(av[2]));
    printf("compressed character: %c\n", compressed);
    //char decompressed[3] = my_readcstr(compressed);
    //my_printf("decompressed result: %s\n", decompressed);
    my_readcstr(compressed);

    return (0);
}
