/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMBN
** File description:
** Task09
*/

void my_putchar(char);

int my_print_combn(int n)
{
    for (int i = 0; i <= n; i++) {
        my_putchar(i+48);
    }
    return (0);
}
