/*
** EPITECH PROJECT, 2021
** MY_STRNCAT
** File description:
** Task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len_dest = 0;

    while (dest[len_dest] != '\0')
        len_dest++;
    while (src[i] != '\0' && i < nb) {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
