/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** free_2d.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void free_2d(int **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map[i]);
    free(map);
}
