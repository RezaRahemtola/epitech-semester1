/*
** EPITECH PROJECT, 2021
** MY_STRNCMP
** File description:
** Task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && i < n) {
        if (s2[i] == '\0')
            return (s1[i]);
        if (s2[i] != s1[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (s1[i] == '\0')
        return (s2[i] * - 1);
    return (s1[n - 1] - s2[n - 1]);
}
