/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** error_manag.c
*/

#include <stdlib.h>
#include "my.h"

int error_lines_carac(char *map, char *nb_lines)
{
    int nb_lines_char = 0;

    for (int count = 0; map[count] != '\0'; count++) {
        if (map[count] == '\n')
            nb_lines_char++;
    }
    if (my_getnbr(nb_lines) != nb_lines_char)
        return (84);
    return (0);
}

char *map_moved(char *map)
{
    while (map[0] != '\n')
        map++;
    map++;
    return (map);
}

int error_nb_carac_bis(char *map, int nb_carac, int *z)
{
    int nb_carac_bis = 0;

    for (; map[*z] != '\n'; *z += 1) {
        if (map[*z] != '.' && map[*z] != 'o' && map[*z] != '\n')
            return (84);
        nb_carac_bis++;
    }
    if (nb_carac_bis != nb_carac)
        return (84);
    *z += 1;
    return (0);
}

int error_nb_carac(char *map, char *nb_lines, int count)
{
    int nb_carac = 0;
    int z = 0;

    map = map_moved(map);
    count += 2;
    for (int i = 0; map[i] != '\n'; i++)
        nb_carac = i + 1;
    for (int count_two = 0; map[count_two] != '\0' && map[z] != '\0';
        count_two++) {
        if (error_nb_carac_bis(map, nb_carac, &z) == 84)
            return (84);
    }
    if (error_lines_carac(map, nb_lines) == 84)
        return (84);
    return (0);
}

int error_manag(int ac, char **av)
{
    char *map;
    char *nb_lines;
    int i = 0;
    int count = 0;

    (void) ac;
    map = map_char(av[1]);
    if (map == NULL)
        return (84);
    for (; map[count] != '\n'; count++) {
        if (map[count] > '9' || map[count] < '0')
            return (84);
    }
    nb_lines = malloc(sizeof(char) * (count + 1));
    for (; map[i] != '\n'; i++)
        nb_lines[i] = map[i];
    nb_lines[i] = '\0';
    if (error_nb_carac(map, nb_lines, count) == 84)
        return (84);
    free(nb_lines);
    return (0);
}
