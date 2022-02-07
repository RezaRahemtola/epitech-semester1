/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** Task07
*/

void my_putchar(char);

void min_value()
{
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
}

int my_put_nbr(int nb)
{
    int next;

    if (nb == 0) {
        my_putchar(48);
        return (0);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    } else if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    if (nb == -2147483648) {
        min_value();
    } else {
        next = nb / 10;
        if (next >= 10) {
            my_put_nbr(next);
        } else {
            my_putchar(next + 48);
        }
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
