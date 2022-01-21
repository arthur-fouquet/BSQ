/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

typedef struct position_t
{
    int a;
    int b;
} position_t;

int **size_map_2d(char *map_1d);
void start_of_a(char **map_1d);
int **map_2d(char *map_1d);
int file_size(char const *filepath);
char *map_char(char const *filepath);
void free_2d(int **map);
int my_getnbr(char const *str);
int error_manag(int ac, char **av);
int error_bis(char *map, char *nb_lines, int count);
int map_2d_nbr(char map);
int algo(int **map, char *map_char);
int nb_lines(char *map);
int nb_columns(char *map);
void my_putchar(char c);
int puissance(int nb);
void display_bsq(int map, int nb_max);
void my_putstr(char const *str);
void from_int_to_char(char *map_char, position_t square, int count);
int my_strlen(char const *str);
void change_nbr(int **map, int x, int y);

#endif
