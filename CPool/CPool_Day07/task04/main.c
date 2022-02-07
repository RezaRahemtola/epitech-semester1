/*
** EPITECH PROJECT, 2021
** main.c MY_PRINT_PARAMS
** File description:
** Task04 main.c
*/

int my_putstr(char *str);

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return (0);
}
