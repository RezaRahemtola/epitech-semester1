/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_IT
** File description:
** Task03
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    for (int i = p; i > 1; i--) {
        result *= nb;
    }
    return (result);
}
