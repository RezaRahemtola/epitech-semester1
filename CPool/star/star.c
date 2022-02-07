/*
** EPITECH PROJECT, 2021
** STAR
** File description:
** Main function
*/

void top(unsigned int size);

void line(unsigned int size);

void middle(unsigned int size);

void bottom(unsigned int size);

void star(unsigned int size)
{
    if (size != 0) {
        top(size);
        line(size);
        middle(size);
        line(size);
        bottom(size);
    }
}
