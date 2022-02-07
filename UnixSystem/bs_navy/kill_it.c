/*
** EPITECH PROJECT, 2021
** bs_navy
** File description:
** Kill it
*/

#include <signal.h>
#include "my.h"

int main(int argc, char **argv)
{
    kill(my_getnbr(argv[1]), SIGQUIT);
    return (0);
}
