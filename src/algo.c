/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** algo.c
*/

#include "my.h"

void change_nbr(int **map, int x, int y)
{
    int xz = x - 1;
    int yz = y - 1;

    if (map[y][x] == 0)
        return;
    if (map[yz][xz] < map[yz][x] && map[yz][xz] < map[y][xz])
        map[y][x] += map[yz][xz];
    else if (map[yz][x] < map[y][xz])
        map[y][x] += map[yz][x];
    else
        map[y][x] += map[y][xz];
}

void add_x(int **map, char *map_char,  int count)
{
    position_t square;
    int x = 0;
    int y = 0;

    square.a = 0;
    square.b = 0;
    while (map[y][x] != count) {
        if (map[y][x] != -1) {
            x++;
        } else {
            x = 0;
            y++;
        }
    }
    if (map[y][x] == count) {
        square.a = x + 1;
        square.b = y + 1;
    }
    from_int_to_char(map_char, square, count);
}

int change_map(int **map, char *map_char, int y, int count)
{
    int xz = 0;
    int columns = nb_columns(map_char);

    for (int x = 1; x < columns; x++) {
        xz = x - 1;
        if (map[y][x] > map[y][xz] && map[y][x] > count)
            count = map[y][x];
    }
    return (count);
}

int algo_two(int **map, char *map_char)
{
    int y = 1;
    int count = 0;
    int lines = nb_lines(map_char);

    while (y != lines) {
        count = change_map(map, map_char, y, count);
        y++;
    }
    add_x(map, map_char, count);
    return (count);
}

int algo(int **map, char *map_char)
{
    int x = 1;
    int i = 1;
    int lines = nb_lines(map_char);
    int columns = nb_columns(map_char);

    for (int y = 1; y < lines; y++) {
        for (; x < columns; x++) {
            change_nbr(map, x, y);
        }
        i++;
        x = 1;
    }
    return (algo_two(map, map_char));
}
