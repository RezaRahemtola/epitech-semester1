/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Task02
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src, int free_src)
{
    int i = 0;
    int len_dest = 0;

    while (dest[len_dest] != '\0')
        len_dest++;
    while (src[i] != '\0') {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    if (free_src) free(src);
    return (dest);
}

char *my_newstrcat(char *str1, char *str2, int free1, int free2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *new_str = malloc(sizeof(char) * len + 1);

    my_strcat(new_str, str1, free1);
    my_strcat(new_str, str2, free1);
    return (new_str);
}
