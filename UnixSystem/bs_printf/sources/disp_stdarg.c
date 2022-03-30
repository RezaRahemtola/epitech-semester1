/*
** EPITECH PROJECT, 2021
** Bootstrap my_printf
** File description:
** disp_stdargs
*/

#include <stdarg.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static void disp_str(char *str)
{
    write(1, str, my_strlen(str));
}

static void disp_int(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb *= -1;
    }
    if (nb <= 9) {
        my_putchar(nb + '0');
    } else {
        disp_int(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void disp_stdarg(char *s, ...)
{
    va_list args;

    va_start(args, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'c')
            my_putchar(va_arg(args, int));
        if (s[i] == 's')
            disp_str(va_arg(args, char *));
        if (s[i] == 'i')
            disp_int(va_arg(args, int));
        my_putchar('\n');
    }
    va_end(args);
}
