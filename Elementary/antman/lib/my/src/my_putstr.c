/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Task02
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
