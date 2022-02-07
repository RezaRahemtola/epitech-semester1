/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Functions for the game board
*/

#include "navy.h"

void disp_board(char **board)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c", board[i][j]);
            my_printf((j != 7) ? " " : "");
        }
        my_printf("\n");
    }
}

int are_all_ships_hit(char **my_board, int enemy_hit)
{
    int my_hit = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            my_hit += (my_board[i][j] == 'x') ? (1) : (0);
    if (my_hit == 14 || enemy_hit == 14)
        return (1);
    return (0);
}

char **create_empty_board(void)
{
    char **board = my_malloc_2d_array(8, 8);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    return (board);
}

char **load_board_from_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    char buff[8] = "\0";
    char **board = create_empty_board();

    if (fd == -1) return (NULL);
    for (int i = 0; i < 4; i++) {
        read(fd, buff, 8);
        board[buff[3] - '1'][buff[2] - 'A'] = buff[0];
        for (int j = buff[2] - 'A'; j < buff[5] - 'A'; j++)
            board[buff[3] - '1'][j] = buff[0];
        board[buff[6] - '1'][buff[5] - 'A'] = buff[0];
        for (int j = buff[3] - '0'; j < buff[6] - '0'; j++)
            board[j][buff[2] - 'A'] = buff[0];
    }
    close(fd);
    return (board);
}

int is_wrong_pos(char const *pos)
{
    if (my_strlen(pos) != 3 || pos[2] != '\n') return (84);
    if (pos[0] - 'A' < 0 || pos[0] - 'A' > 7) return (84);
    if (pos[1] - '1' < 0 || pos[1] - '1' > 7) return (84);
    return (0);
}
