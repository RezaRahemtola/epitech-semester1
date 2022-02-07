/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Task02
*/

char *my_strcat(char *dest, char const *src)
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
    return (dest);
}
