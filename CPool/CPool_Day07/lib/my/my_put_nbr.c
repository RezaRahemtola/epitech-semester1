/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** Task07
*/

void my_putchar(char);

static int min_value(int nb)
{
    if (nb == -2147483648) {
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return (1);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int next;
    int nbr_to_display;

    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    } else if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    if (min_value(nb) == 0) {
        next = nb / 10;
        nbr_to_display = (next >= 10) ? (next) : (next + 48);
        my_put_nbr(nbr_to_display);
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
