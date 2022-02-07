/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_FACTORIAL_IT
** File description:
** Task01
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12) {
        return (0);
    } else if (nb == 0) {
        return (1);
    }
    for (int i = nb; i > 1; i--) {
        result *= i;
    }
    return (result);
}
