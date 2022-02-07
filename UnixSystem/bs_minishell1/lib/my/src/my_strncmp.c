/*
** EPITECH PROJECT, 2021
** MY_STRNCMP
** File description:
** Task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    if (i < n)
        return (s1[i] - s2[i]);
    return (0);
}
