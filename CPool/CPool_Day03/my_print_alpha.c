/*
** EPITECH PROJECT, 2021
** MY_PRINT_ALPHA
** File description:
** Task 01
*/
int my_putchar(char);

int my_print_alpha(void)
{
    for (int i = 97; i <= 122; i++) {
        my_putchar(i);
    }
    return (0);
}
