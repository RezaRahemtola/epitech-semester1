/*
** EPITECH PROJECT, 2021
** main.c MY_REV_PARAMS
** File description:
** Task05
*/

int my_putstr(char *str);

int main(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return (0);
}
