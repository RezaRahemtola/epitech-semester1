/*
** EPITECH PROJECT, 2021
** MY_STRNCMP
** File description:
** Task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result_s1 = 0;
    int result_s2 = 0;
    int i = 0;

    while (s1[i] != '\0' && i < n) {
        result_s1 += s1[i];
        i++;
    }
    i = 0;
    while (s2[i] != '\0' && i < n) {
        result_s2 += s2[i];
        i++;
    }
    return (result_s1 - result_s2);
}
