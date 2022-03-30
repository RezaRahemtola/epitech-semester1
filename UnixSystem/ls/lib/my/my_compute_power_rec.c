/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_REC
** File description:
** Task04
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 1)
        return (nb);
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}
