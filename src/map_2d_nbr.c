/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** map_2d_nbr.c
*/

#include "my.h"

int map_2d_nbr(char map)
{
    if (map == 'o')
        map = 0;
    else
        map = 1;
    return (map);
}
