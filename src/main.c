/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int test_case(char *map_1d)
{
    int a = 0;
    int b = 0;

    if (nb_lines(map_1d) == 1) {
        for (; map_1d[a] != '.' && map_1d[a] != '\0'; a++);
        map_1d[a] = 'x';
        return (1);
    }
    if (nb_columns(map_1d) == 1) {
        for (; map_1d[b] != '.' && map_1d[b] != '\0'; b++);
        map_1d[b] = 'x';
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int **map;
    char *map_1d;

    if (ac != 2)
        return (84);
    if (error_manag(ac, av) == 84)
        return (84);
    map_1d = map_char(av[1]);
    if (test_case(map_1d) == 1) {
        while (map_1d[0] != '\n')
            map_1d++;
        map_1d++;
        write(1, map_1d, my_strlen(map_1d));
        return (0);
    } else {
        map = map_2d(map_1d);
        algo(map, map_1d);
        free_2d(map);
    }
    return (0);
}
