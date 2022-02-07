/*
** EPITECH PROJECT, 2021
** mem_alloc
** File description:
** Part 3 Step 1
*/

#include <stdlib.h>
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);

char *mem_alloc(char const *a, char const *b)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)));

    my_strcat(new_str, a);
    my_strcat(new_str, b);
    return (new_str);
}
