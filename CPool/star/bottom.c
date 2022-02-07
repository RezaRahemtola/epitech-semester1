/*
** EPITECH PROJECT, 2021
** STAR_BOTTOM
** File description:
** Display the bottom of the star
*/

void my_putchar(char c);

void print_spaces(int spaces);

void bottom(unsigned int size)
{
    int spaces_before = 2 * size;
    int spaces_between = 2 * size - 3;

    if (size == 1)
        spaces_before++;
    while (spaces_between >= 1) {
        print_spaces(spaces_before);
        spaces_before++;
        my_putchar('*');
        print_spaces(spaces_between);
        spaces_between -= 2;
        my_putchar('*');
        my_putchar('\n');
    }
    print_spaces(spaces_before);
    my_putchar('*');
    my_putchar('\n');
}
