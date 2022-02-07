/*
** EPITECH PROJECT, 2021
** CONCAT_PARAMS
** File description:
** Task02
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *concat_params(int argc, char **argv)
{
    int total_len = argc;
    char *result;
    int i = 0;

    for (i = 0; i < argc; i++)
        total_len += my_strlen(argv[i]);
    result = malloc(sizeof(char) * total_len);
    i = 0;
    while (i < argc) {
        my_strcat(result, argv[i]);
        if (i != argc - 1)
            my_strcat(result, "\n");
        i++;
    }
    return (result);
}
