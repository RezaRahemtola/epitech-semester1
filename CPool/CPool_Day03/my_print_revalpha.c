/*
** EPITECH PROJECT, 2021
** MY_PRINT_REVALPHA
** File description:
** Task02
*/
void my_putchar(char);

int my_print_revalpha(void)
{
    int i;

    for (i = 122; i >= 97; i--) {
        my_putchar(i);
    }
    return (0);
}
