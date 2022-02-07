/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMB
** File description:
** Task06
*/

void my_putchar(char);

int display_combinations(int a, int b) {
    my_putchar((a / 10)+48);
    my_putchar((a % 10)+48);
    my_putchar(' ');
    my_putchar((b / 10)+48);
    my_putchar((b % 10)+48);
    if (a == 98 && b == 99) {
        return (0);
    }
    my_putchar(',');
    my_putchar(' ');
    return (0);
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 0;

    while (a <= 99) {
        b = a + 1;
        while (b <= 99) {
            display_combinations(a, b);
            b++;
        }
        a++;
    }
    return (0);
}
