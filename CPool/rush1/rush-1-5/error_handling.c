/*
** EPITECH PROJECT, 2021
** Rush1
** File description:
** Error handling for Rush 1
*/

#include <unistd.h>

void error_handling(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
    }
}
