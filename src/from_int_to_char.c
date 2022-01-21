/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** from_int_to_char.c
*/

#include <unistd.h>
#include "my.h"

void from_int_to_char(char *map_char, position_t square, int count)
{
    int q = 0;
    int nb_c = nb_columns(map_char) + 1;

    while (*map_char != '\n')
        map_char++;
    map_char++;
    q = (nb_c) * (square.b - 1) + square.a;
    for (int a = 1; a <= count; a++) {
        for (int ref = q - count; q > ref; ref++) {
            map_char[ref] = 'x';
        }
        q = q - nb_c;
    }
    write(1, map_char, my_strlen(map_char));
}
