/*
** EPITECH PROJECT, 2022
** mylib
** File description:
** Function to malloc and fill a string with a given char
*/

#include <stdlib.h>

char *my_malloc_str(size_t nb_char, char c)
{
    char *str = malloc(sizeof(char) * nb_char);

    for (size_t i = 0; i < nb_char; i++)
        str[i] = c;
    return (str);
}
