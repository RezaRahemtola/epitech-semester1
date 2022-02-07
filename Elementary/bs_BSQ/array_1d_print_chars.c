/*
** EPITECH PROJECT, 2021
** array_1d_print_chars
** File description:
** Part 2 Step 1
*/

void my_putchar(char c);

void array_1d_print_chars(char const *arr)
{
    for (int i = 0; arr[i] != '\0'; i++) {
        my_putchar(arr[i]);
        my_putchar('\n');
    }
}
