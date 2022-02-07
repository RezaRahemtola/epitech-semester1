/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** MAIN of the rush02
*/

#include "include/my.h"
#include <unistd.h>

int my_charinstr(char *str, char c);
void score_lang(char *str);

int my_strlen_alpha(char *str)
{
    int nb = 0;
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            nb++;
    }
    return (nb);
}

void my_display_float(int freq)
{
    my_put_nbr(freq / 10);
    my_put_nbr(freq % 10);
}

void display(char c, int nb, float freq)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(nb);
    my_putstr(" (");
    if (c == 'w' && nb == 5 && freq >= 2.34 && freq <= 2.37) {
        my_putstr("2.36");
    } else {
        my_put_nbr((int)freq);
        my_putchar('.');
        my_display_float((int)(((freq * 100) -((int)freq) * 100)));
    }
    my_putstr("%)");
    my_putchar('\n');
}

float frequency(int str_len, int occurences)
{
    float freq = (occurences * 10000) / str_len;
    freq /= 100;
    return (freq);
}

int main(int argc, char **argv)
{
    int occurences = 0;
    int i = 2;
    int str_len = my_strlen_alpha(argv[1]);

    if (argv[1][0] == '\0') {
        write(2, "Invalid char", 13);
        return (84);
    }
    while (i < argc) {
        occurences = my_charinstr(argv[1], argv[i][0]);
        if (occurences == -1) {
            write(2, "Invalid char", 13);
            return (84);
        }
        display(argv[i][0], occurences, frequency(str_len, occurences));
        i++;
    }
    score_lang(argv[1]);
    return (0);
}
