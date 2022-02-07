/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMB
** File description:
** Task05
*/

void my_putchar(char);

int display_comb(int a, int b, int c)
{
    if (a != b && b != c && a != c && c > b && b > a) {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        if (a == 55 && b == 56 && c == 57) {
	    return (0);
        }
        my_putchar(44);
        my_putchar(32);
    }
    return (0);
}

int my_print_comb(void)
{
    int a = 48;
    int b = 49;
    int c = 50;

    while (a < 56) {
        display_comb(a, b, c);
        c++;
        if (c > 57) {
            c = 48;
            b++;
        }
        if (b > 57) {
            b = 48;
            a++;
        }
    }
    return (0);
}
