/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** ça fait long là
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else if (n >= 0) {
        my_putchar('P');
    }
    return (0);
}
