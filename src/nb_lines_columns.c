/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** nb_lines_columns.c
*/

#include <stddef.h>
#include "my.h"

int nb_lines(char *map)
{
    int a = 0;
    int i = 0;

    while (map[a] != '\0') {
        if (map[a] == '\n')
            i++;
        a++;
    }
    i--;
    return (i);
}

int nb_columns(char *map)
{
    int b = 0;
    int a = 0;

    while (map[b] != '\n')
        b++;
    b++;
    while (map[b] != '\0' && map[b] != '\n') {
        b++;
        a++;
    }
    return (a);
}
