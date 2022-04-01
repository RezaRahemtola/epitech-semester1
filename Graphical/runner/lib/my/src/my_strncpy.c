/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** Task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int strlen = 0;

    while (src[n - 1] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (src[strlen] != '\0')
        strlen++;
    if (n > strlen)
        dest[i] = '\0';
    return (dest);
}
