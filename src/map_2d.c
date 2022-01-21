/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** map_2d.c
*/

#include <stdlib.h>
#include "my.h"

int **size_map_2d(char *map_1d)
{
    int i = 0;
    int mallo_size = 0;
    int **map_2d;

    while (map_1d[i] != '\n') {
        mallo_size = (mallo_size * 10) + (map_1d[i] - '0');
        i++;
    }
    map_2d = malloc(sizeof(int *) * (mallo_size + 1));
    if (map_2d == NULL)
        return (NULL);
    for (int mallo = 0; mallo < mallo_size; mallo++) {
        map_2d[mallo] = malloc(sizeof(int) * (nb_columns(map_1d) + 1));
        if (map_2d[mallo] == NULL)
            return (NULL);
    }
    map_2d[mallo_size] = NULL;
    return (map_2d);
}

void start_of_a(char **map_1d)
{
    while (**map_1d != '\n')
        (*map_1d)++;
    (*map_1d)++;
}

int **map_2d(char *map_1d)
{
    int **map_2d = size_map_2d(map_1d);
    int a = 0;
    int b = 0;
    int c = 0;

    start_of_a(&map_1d);
    while (map_1d[a] != '\0') {
        for (; map_1d[a] != '\n' && map_1d[a] != '\0'; c++) {
            map_2d[b][c] = map_2d_nbr(map_1d[a]);
            a++;
        }
        map_2d[b][c] = -1;
        a++;
        b++;
        c = 0;
    }
    return (map_2d);
}
