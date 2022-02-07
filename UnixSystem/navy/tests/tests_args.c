/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** Tests arguments
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(error_handling, dash_h_error)
{
    char *argv[2] = {"./navy", "-h"};
    int argc = 2;

    cr_assert_eq(check_errors(argc, argv), 0);
}

Test(error_handling, not_enough_args, .init=cr_redirect_stderr)
{
    char *argv[1] = {"./navy"};
    int argc = 1;

    check_errors(argc, argv);
    cr_expect_stderr_eq_str("./navy: Invalid number of arguments\nretry with -h\n");
}

Test(error_handling, too_many_args, .init=cr_redirect_stderr)
{
    char *argv[4] = {"./navy", "arg2", "arg3", "arg4"};
    int argc = 4;

    check_errors(argc, argv);
    cr_expect_stderr_eq_str("./navy: Invalid number of arguments\nretry with -h\n");
}

Test(error_handling, one_arg_invalid_file, .init=cr_redirect_stderr)
{
    char *argv[2] = {"./navy", "unknown_file.txt"};
    int argc = 2;

    check_errors(argc, argv);
    cr_expect_stderr_eq_str("./navy: File not found\nretry with -h\n");
}

Test(error_handling, one_arg_correct_file)
{
    char *argv[2] = {"./navy", "tests/samples/pos1"};
    int argc = 2;

    cr_assert_eq(check_errors(argc, argv), 0);
}

Test(error_handling, one_arg_incorrect_boat_pos, .init=cr_redirect_stderr)
{
    char *argv[2] = {"./navy", "tests/samples/wrong_pos"};
    int argc = 2;

    check_errors(argc, argv);
    cr_expect_stderr_eq_str("./navy: Invalid file: incorrect boat position.\n./navy: Invalid file: position doesn't match size\n");
}

Test(error_handling, two_args_invalid_file, .init=cr_redirect_stderr)
{
    char *argv[3] = {"./navy", "42" "unknown_file.txt"};
    int argc = 3;

    check_errors(argc, argv);
    cr_expect_stderr_eq_str("./navy: File not found\nretry with -h\n");
}
