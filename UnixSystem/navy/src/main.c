/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main
*/

#include "navy.h"

navy_info_t *navy_info;

static void disp_help(void)
{
    my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n     first_player_pid: ");
    my_printf("only for the 2nd player. pid of the first player.\n");
    my_printf("     navy_positions: ");
    my_printf("file representing the positions of the ships.\n");
}

static void disp_end_message(int won)
{
    if (won)
        my_printf("I won\n");
    else
        my_printf("Enemy won\n");
}

int main(int argc, char **argv)
{
    int player = (argc == 2) ? (1) : (2);
    int won = -1;

    if (check_errors(argc, argv) == 1) return (84);
    if (my_strcmp(argv[1], "-h") == 0) {
        disp_help();
        return (0);
    }
    navy_info = malloc(sizeof(navy_info_t));
    navy_info->enemy_hit = 0;
    my_printf("my_pid: %d\n", getpid());
    if (player == 1)
        won = connect_player1(argv[1]);
    else
        won = connect_player2(my_getnbr(argv[1]), argv[2]);
    disp_end_message(won);
    return (won);
}
