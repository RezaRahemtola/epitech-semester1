/*
** EPITECH PROJECT, 2021
** Rush1 Assignement1
** File description:
** Rush1
*/

void my_putchar(char c);

void error_handling(int x, int y);

void display_border(int lines, int last_line, int columns, int last_column)
{
    if (lines != 0 && lines != last_line) {
        if (columns == 0 || columns == last_column) {
            my_putchar('|');
        } else {
            my_putchar(' ');
        }
    }
}

void display_first_last_lines(int lines, int last_l, int columns, int last_c)
{
    if (lines == 0 || lines == last_l) {
        if (columns == 0 || columns == last_c) {
            my_putchar('o');
        } else {
            my_putchar('-');
        }
    }
}

void rush(int x, int y)
{
    int last_line = y - 1;
    int last_column = x - 1;

    error_handling(x, y);
    for (int lines = 0; lines < y; lines++) {
        for (int columns = 0; columns < x; columns++) {
            display_border(lines, last_line, columns, last_column);
            display_first_last_lines(lines, last_line, columns, last_column);
        }
        if (x > 0) {
            my_putchar('\n');
        }
    }
}
