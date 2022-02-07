/*
** EPITECH PROJECT, 2021
** rush_1-2
** File description:
** Rush2
*/

void my_putchar(char c);

void error_handling(int x, int y);

void display_real_square_f_l_lines(int l, int last_l, int c, int last_c)
{
    if ((c == 0 && l == 0) || (c == last_c && l == last_l)) {
        my_putchar('/');
    } else if ((c == last_c && l == 0) || (c == 0 && l == last_l)) {
        my_putchar('\\');
    } else {
        my_putchar('*');
    }
}

void display_first_last_lines(int lines, int last_l, int columns, int last_c)
{
    int x = last_c + 1;
    int y = last_l + 1;

    if (lines == 0 || lines == last_l) {
        if (x == 1 || y == 1) {
            my_putchar('*');
        } else {
            display_real_square_f_l_lines(lines, last_l, columns, last_c);
        }
    }
}

void display_border(int lines, int last_line, int columns, int last_column)
{
    if (lines != 0 && lines != last_line) {
        if (columns == 0 || columns == last_column) {
            my_putchar('*');
        } else {
            my_putchar(' ');
        }
    }
}

void rush(int x, int y)
{
    int last_column = x - 1;
    int last_line = y - 1;

    error_handling(x, y);
    for (int lines = 0; lines < y; lines++) {
        for (int columns = 0; columns < x; columns++) {
            display_first_last_lines(lines, last_line, columns, last_column);
            display_border(lines, last_line, columns, last_column);
        }
        if (x > 0)
            my_putchar('\n');
    }
}
