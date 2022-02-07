/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Tests for gam board functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(game_board, disp_board, .init=cr_redirect_stdout)
{
    char **board = my_malloc_2d_array(8, 8);
    board[0] = "o.xo.o.o";
    board[1] = "..2..o..";
    board[2] = ".o..o...";
    board[3] = "...xxx..";
    board[4] = ".xo..oo.";
    board[5] = ".x......";
    board[6] = "ox.xxx55";
    board[7] = ".x.o.o.o";

    disp_board(board);
    cr_assert_stdout_eq_str(" |A B C D E F G H\n"
                            "-+---------------\n"
                            "1|o . x o . o . o\n"
                            "2|. . 2 . . o . .\n"
                            "3|. o . . o . . .\n"
                            "4|. . . x x x . .\n"
                            "5|. x o . . o o .\n"
                            "6|. x . . . . . .\n"
                            "7|o x . x x x 5 5\n"
                            "8|. x . o . o . o\n");
}

Test(game_board, are_all_ships_hit_false)
{
    char **board = my_malloc_2d_array(8, 8);
    board[0] = "o.xo.o.o";
    board[1] = "..2..o..";
    board[2] = ".o..o...";
    board[3] = "...xxx..";
    board[4] = ".xo..oo.";
    board[5] = ".x......";
    board[6] = "ox.xxx55";
    board[7] = ".x.o.o.o";

    cr_assert_eq(are_all_ships_hit(board, 0), 0);
}

Test(game_board, are_all_ships_hit_true_enemy)
{
    char **board = my_malloc_2d_array(8, 8);
    board[0] = ".xx5xx.x";
    board[1] = "...o.o.x";
    board[2] = ".o....ox";
    board[3] = "..xxo..o";
    board[4] = ".....o..";
    board[5] = ".o..xxxx";
    board[6] = "..o...o.";
    board[7] = ".....o..";

    cr_assert_eq(are_all_ships_hit(board, 14), 1);
}

Test(game_board, are_all_ships_hit_true)
{
    char **board = my_malloc_2d_array(8, 8);
    board[0] = ".xxxxx.x";
    board[1] = "...o.o.x";
    board[2] = ".o....ox";
    board[3] = "..xxo..o";
    board[4] = ".....o..";
    board[5] = ".o..xxxx";
    board[6] = "..o...o.";
    board[7] = ".....o..";

    cr_assert_eq(are_all_ships_hit(board, 0), 1);
}

Test(game_board, load_board_from_file, .init=cr_redirect_stdout)
{
    char **board = load_board_from_file("tests/samples/pos1");

    disp_board(board);
    cr_assert_stdout_eq_str(" |A B C D E F G H\n"
                            "-+---------------\n"
                            "1|. . 2 . . . . .\n"
                            "2|. . 2 . . . . .\n"
                            "3|. . . . . . . .\n"
                            "4|. . . 3 3 3 . .\n"
                            "5|. 4 . . . . . .\n"
                            "6|. 4 . . . . . .\n"
                            "7|. 4 . 5 5 5 5 5\n"
                            "8|. 4 . . . . . .\n");
}

Test(game_board, is_wrong_pos_valid)
{
    cr_assert_eq(is_wrong_pos("D2\n"), 0);
}

Test(game_board, is_wrong_pos_invalid_one)
{
    cr_assert_eq(is_wrong_pos("I7\n"), 84);
}

Test(game_board, is_wrong_pos_invalid_two)
{
    cr_assert_eq(is_wrong_pos("A9\n"), 84);
}

Test(game_board, is_wrong_pos_invalid_last_char)
{
    cr_assert_eq(is_wrong_pos("A55"), 84);
}
