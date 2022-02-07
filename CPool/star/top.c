/*
** EPITECH PROJECT, 2021
** STAR_TOP
** File description:
** Handle the display of the top of the star
*/

void my_putchar(char c);

void print_spaces(int spaces);

void top(unsigned int size)
{
    int spaces_before = (size * 3) - 1;
    int lines = size - 1;
    int spaces_between = 1;

    if (size == 1)
        spaces_before++;
    print_spaces(spaces_before);
    my_putchar('*');
    my_putchar('\n');
    spaces_before--;
    while (lines > 0) {
        print_spaces(spaces_before);
        my_putchar('*');
        print_spaces(spaces_between);
        my_putchar('*');
        my_putchar('\n');
        spaces_before--;
        spaces_between += 2;
        lines--;
    }
}
