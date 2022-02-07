/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_FACTORIAL_REC
** File description:
** Task02
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 1) {
        return (1);
    }
    if (nb < 0 || nb > 12) {
        return (0);
    } else if (nb == 0) {
        return (1);
    }
    return (nb * my_compute_factorial_rec(nb - 1));
}
