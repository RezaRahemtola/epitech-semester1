/*
** EPITECH PROJECT, 2021
** COUNT_ISLAND
** File description:
** Mini-Project 2
*/

int check_proximity(char **world, int line, int col, int island_nbr)
{
    int current_char = world[line][col];

    if (current_char != 'X' && current_char != 'x')
        return (0);
    world[line][col] = island_nbr + 47;
    check_proximity(world, line, col + 1, island_nbr);
    if (line > 0)
        check_proximity(world, line - 1, col, island_nbr);
    if (world[line + 1] != 0)
        check_proximity(world, line + 1, col, island_nbr);
    if (col > 0)
        check_proximity(world, line, col - 1, island_nbr);
    return (0);
}

int check_island(char **world, int line, int column, int island_nbr)
{
    if (world[line][column] == 'X' || world[line][column] == 'x') {
        island_nbr++;
        world[line][column] = island_nbr + 47;
        check_proximity(world, line, column + 1, island_nbr);
        if (line > 0)
            check_proximity(world, line - 1, column, island_nbr);
        if (world[line + 1] != 0)
            check_proximity(world, line + 1, column, island_nbr);
        if (column > 0)
            check_proximity(world, line, column - 1, island_nbr);
        return (island_nbr);
    }
    return (island_nbr);
}

int count_island(char **world)
{
    int island_nbr = 0;

    for (int line = 0; world[line] != 0; line++) {
        for (int column = 0; world[line][column] != '\0'; column++)
            island_nbr = check_island(world, line, column, island_nbr);
    }
    return (island_nbr);
}
