/*
** EPITECH PROJECT, 2021
** MY_PRINT_DIGITS
** File description:
** Task03
*/

void my_putchar(char);

int my_print_digits(void)
{
    int i;

    for (i = 48; i <= 57; i++) {
        my_putchar(i);
    }
    return (0);
}
