/*
** EPITECH PROJECT, 2021
** STAR_LINE
** File description:
** Handle the display of lines
*/

void my_putchar(char c);

void print_spaces(int spaces);

void line(unsigned int size)
{
    int stars = (2 * size) + 1;
    int spaces = 2 * (size - 2) + 1;

    if (size == 1)
        spaces += 2;
    for (int i = 0; i < stars; i++) {
        my_putchar('*');
    }
    print_spaces(spaces);
    for (int i = 0; i < stars; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
}
