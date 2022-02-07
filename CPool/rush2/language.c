/*
** EPITECH PROJECT, 2021
** LANGUAGE
** File description:
** find the language with the letter frequency
*/

#include "include/my.h"

int my_charinstr(char *str, char c);
float frequency(int str_len, int occurences);
int my_strlen_alpha(char *str);

float check_fr(char *str, int i)
{
    int oc = 0;
    int len = my_strlen_alpha(str);
    float fr[26] = {7.636, 0.901, 3.260, 3.669, 14.715, 1.066, 0.866, 0.737,
    7.529, 0.613, 0.074, 5.456, 2.968, 7.095, 5.796, 2.521, 1.362, 6.693,
    7.948, 7.244, 6.311, 1.838, 0.049, 0.427, 0.128, 0.326};
    float freq = 0;

    oc = my_charinstr(str, 'a' + i);
    freq = frequency(len, oc);
    return (ABS(fr[i] - freq));
}

float check_all(char *str, int i)
{
    int oc = 0;
    int len = my_strlen_alpha(str);
    float al[26] = {6.516, 1.886, 2.732, 5.076, 16.396, 1.656, 3.009, 4.577,
    6.550, 0.268, 1.417, 3.437, 2.534, 9.776, 2.594, 0.670, 0.018, 7.003,
    7.270, 6.154, 4.166, 0.846, 1.921, 0.034, 0.039, 1.134};
    float freq = 0;

    oc = my_charinstr(str, 'a' + i);
    freq = frequency(len, oc);
    return (ABS(al[i] - freq));
}

float check_eng(char *str, int i)
{
    int oc = 0;
    int len = my_strlen_alpha(str);
    float en[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094,
    6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
    6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};
    float freq = 0;

    oc = my_charinstr(str, 'a' + i);
    freq = frequency(len, oc);
    return (ABS(en[i] - freq));
}

float check_esp(char *str, int i)
{
    int oc = 0;
    int len = my_strlen_alpha(str);
    float es[26] = {11.525, 2.215, 4.019, 5.010, 12.181, 0.692, 1.768, 0.703,
    6.247, 0.493, 0.011, 4.967,3.157, 6.712, 8.683, 2.510, 0.877, 6.871,
    7.977, 4.632, 2.927, 1.138, 0.017, 0.215, 1.008, 0.467};
    float freq = 0;

    oc = my_charinstr(str, 'a' + i);
    freq = frequency(len, oc);
    return (ABS(es[i] - freq));
}

void score_lang(char *str)
{
    float sc[] = {0, 0, 0, 0};
    int i = 0;

    while (i < 26) {
        sc[1] = sc[1] + check_fr(str, i);
        sc[2] = sc[2] + check_all(str, i);
        sc[3] = sc[3] + check_eng(str, i);
        sc[4] = sc[4] + check_esp(str, i);
        i++;
    }
    if (sc[1] < sc[2] && sc[1] < sc[3] && sc[1] < sc[4])
        my_putstr("=> French");
    if (sc[2] < sc[1] && sc[2] < sc[3] && sc[2] < sc[4])
        my_putstr("=> German");
    i++;
    if (sc[3] < sc[1] && sc[3] < sc[2] && sc[3] < sc[4])
        my_putstr("=> English");
    if (sc[4] < sc[1] && sc[4] < sc[3] && sc[4] < sc[2])
        my_putstr("=> Spanish");
}
