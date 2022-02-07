/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Core game functions
*/

#include "navy.h"

static int binary_to_number(char *str, int base)
{
    int nb = 0;

    nb = nb + (str[3] - base) * 1;
    nb = nb + ((str[2] - base) * 2);
    nb = nb + ((str[1] - base) * 2 * 2);
    nb = nb + ((str[0] - base) * 2 * 2 * 2);
    return (nb);
}

char *binary_to_pos(void)
{
    char line[5];
    char *cols = my_strdup(&navy_info->sig_str[4]);
    char *pos = malloc(sizeof(char) * 3);

    my_strncpy(line, navy_info->sig_str, 4);
    pos[0] = binary_to_number(line, '0') + '0';
    pos[1] = binary_to_number(cols, '0') + '0';
    pos[2] = '\0';
    free(cols);
    return (pos);
}

static void disp_game_boards(char **my_board, char **enemy_board)
{
    my_printf("my positions:\n");
    disp_board(my_board);
    my_printf("\nenemy's positions:\n");
    disp_board(enemy_board);
    my_printf("\n");
}

static void play(int playing, char *pos, char **my_board, char **enemy_board)
{
    disp_game_boards(my_board, enemy_board);
    if (playing == 0) {
        defend(pos, my_board);
        if (are_all_ships_hit(my_board, navy_info->enemy_hit) == 1) return;
        attack_enemy(pos, enemy_board);
    } else {
        attack_enemy(pos, enemy_board);
        if (are_all_ships_hit(my_board, navy_info->enemy_hit) == 1) return;
        defend(pos, my_board);
    }
}

int play_game(char *pos_path, int playing)
{
    char **my_board = load_board_from_file(pos_path);
    char **enemy_board = create_empty_board();
    char *pos = malloc(sizeof(char) * 3);

    while (are_all_ships_hit(my_board, navy_info->enemy_hit) == 0)
        play(playing, pos, my_board, enemy_board);
    disp_game_boards(my_board, enemy_board);
    free(my_board);
    free(enemy_board);
    free(pos);
    return ((navy_info->enemy_hit == 14) ? (1) : (0));
}
