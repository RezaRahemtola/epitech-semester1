/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_SQUARE_ROOT
** File description:
** Task05
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (int i = 1; nb > 0; i += 2) {
        nb -= i;
        result++;
    }
    if (nb == 0) {
        return (result);
    } else {
        return (0);
    }
}
