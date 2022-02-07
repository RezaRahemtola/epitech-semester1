/*
** EPITECH PROJECT, 2022
** bs minishell
** File description:
** segfaulting master
*/

void main(void)
{
    char *str = "Hello World";

    str[42] = '\0';
}
