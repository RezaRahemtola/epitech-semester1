/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** Task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
