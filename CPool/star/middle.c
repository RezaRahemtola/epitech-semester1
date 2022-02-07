/*
** EPITECH PROJECT, 2021
** STAR_MIDDLE
** File description:
** Display the middle of the star
*/

void my_putchar(char c);

void print_spaces(int spaces);

void middle(unsigned int size)
{
    unsigned int spaces_before = 1;
    int line_char = (2 * size + 1) * 2 + 2 * (size - 2);
    int spaces_between = line_char - (spaces_before * 2) - 1;
    int increment = 1;

    if (size == 1)
        spaces_between += 2;
    while (spaces_before >= 1) {
        print_spaces(spaces_before);
        if (spaces_before == size)
            increment = - 1;
        spaces_before += increment;
        my_putchar('*');
        print_spaces(spaces_between);
        spaces_between = line_char - (spaces_before * 2) - 1;
        my_putchar('*');
        my_putchar('\n');
    }
}
