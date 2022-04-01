/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** Task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s2[i] == '\0')
            return (s1[i]);
        if (s2[i] != s1[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
